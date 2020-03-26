#include <iostream>
#include <thread>
#include <deque>
#include <memory>
#include <cstring>
#include <functional>
#include "asio.hpp"
#include "netpacket.h"
#include "cs.pb.h"
#include "google/protobuf/text_format.h"
using namespace std;

using asio::ip::tcp;
using asio::ip::make_address_v4;

#define SERV_PORT 11000

class chat_client;

using chat_client_ptr = std::shared_ptr<chat_client>;

// Packet优化：Packet的内存分配优化，将Packet变成POD对象,
class chat_client : public std::enable_shared_from_this<chat_client>
{
public:
    chat_client(asio::io_context& io_context,
                 tcp::endpoint endpoint)
        : io_context_(io_context),
          remote_addr_(std::move(endpoint)),
          socket_(io_context)
    {
    }

    void start()
    {
        // SO_REUSEADDR选项表示可以使用处于TIME_WAIT的socket的端口
        // 注意socket要先open
        //socket_.open(tcp::v4());
        //socket_.set_option(tcp::socket::reuse_address(true));

        auto self(shared_from_this());
        cout << "prepare_write_msgs\n";
        prepare_write_msgs();
        cout << "async_connect\n";
        socket_.async_connect(remote_addr_,
                              [this, self](std::error_code ec)
                              {
                                  if (!ec)
                                  {
                                      do_read_header();
                                      do_write();
                                  }
                                  else
                                  {
                                      cout << "conn error" << endl;
                                  }

                              });
        auto R = [this]{
            io_context_.run();
            cout << "after io_context run" << endl;
        };
        // 析构一个"joinable"的std::thread会抛出一个错误
        // 因此我们在析构std::thread前必须让它join或者detach
        // 另外：默认构造的std::thread不是joinable的，被移动过的thread也不是joinable的
        // 对std::thread执行detach后，线程的执行就与这个std::thread对象无关了，取决于系统级别的线程
        // 如果想知道detach的线程的执行结果，需要通过其他手段了，例如生产消费模型，或者future
        std::thread t(R);
        t.detach();
    }

    void close()
    {
        asio::post(io_context_, [this]() { socket_.close(); });
    }
    NetPacket *receive()
    {
        std::lock_guard<std::mutex> lock(client_mutex_);
        NetPacket *p = nullptr;
        if(!packet_queue_.empty())
        {
            p = packet_queue_.front();
            packet_queue_.pop_front();
        }
        //cout << "pop packet_queue size: " << packet_queue_.size() << endl;
        return p;
    }
    void deallocatePacket(NetPacket *packet)
    {
        if(nullptr != packet){
            delete packet;
        }

    }

private:
    void do_read_header()
    {
        auto self(shared_from_this());
        asio::async_read(socket_,
                         asio::buffer(read_msg_.data(), NetPacket::HEADER_LENGTH),
                         [this, self](std::error_code ec, std::size_t /*length*/)
                         {
                             if (!ec && read_msg_.decodeHeader())
                             {
                                 do_read_body();
                             }
                             else
                             {
                                 socket_.close();
                             }
                         });
    }

    void do_read_body()
    {
        auto self(shared_from_this());
        asio::async_read(socket_,
                         asio::buffer(read_msg_.body(), read_msg_.bodyLength()),
                         [this, self](std::error_code ec, std::size_t /*length*/)
                         {
                             if (!ec)
                             {
                                 NetPacket *packet = allocatePacket();
                                 memcpy(packet->data(), read_msg_.data(), read_msg_.length());
                                 packet->bodyLength(read_msg_.bodyLength());
                                 pushPacket(packet);
                                 do_read_header();
                             }
                             else
                             {
                                 socket_.close();
                             }
                         });
    }

    void do_write()
    {
        cout << "BodyLength: " << write_msgs_.front().bodyLength() << endl;
        auto self(shared_from_this());   // 一定要记得让lambda持有该对象的shared_ptr
        asio::async_write(socket_,
                          asio::buffer(write_msgs_.front().data(),
                                       write_msgs_.front().length()),
                          [this, self](std::error_code ec, std::size_t /*length*/)
                          {
                              cout << "async_write return\n";
                              if (!ec)
                              {
                                  write_msgs_.pop_front();
                                  if (!write_msgs_.empty())
                                  {
                                      do_write();
                                  }
                              }
                              else
                              {
                                  cout << "I'm closed" << endl;
                                  google::protobuf::ShutdownProtobufLibrary();
                                  socket_.close();
                              }
                          });
    }

    void prepare_write_msgs()
    {
        string longStr(2000, 'A');
        for(int i=0;i<10;i++)
        {
            Hello h;
            char ss[128];
            sprintf(ss, "蕉兵必败 %d",i);
            h.set_acc_name(ss);
            h.set_passwd("11111111");
            string h_data;
            h.SerializeToString(&h_data);
            NetPacket packet;
            memcpy(packet.body(), h_data.data(), h_data.length());
            packet.bodyLength(h_data.length());
            packet.encodeHeader();
            write_msgs_.push_back(packet);
        }
    }
    NetPacket *allocatePacket()
    {
        NetPacket *p = new NetPacket;
        return p;
    }
    void pushPacket(NetPacket *packet)
    {
        std::lock_guard<std::mutex> lock(client_mutex_);
        packet_queue_.push_back(packet);
        //cout << "push packet_queue size: " << packet_queue_.size() << endl;
    }
    asio::io_context& io_context_;
    tcp::endpoint remote_addr_;
    tcp::socket socket_;
    NetPacket read_msg_;
    std::deque<NetPacket> write_msgs_;
    std::deque<NetPacket*> packet_queue_;
    std::mutex client_mutex_;
};

class GameLoop
{
public:
    GameLoop(chat_client_ptr client):stopped_(false),client_(std::move(client)){}
    void Run()
    {
        cout << "GameLoop Run\n";
        while(!stopped_)
        {
            Update();
            this_thread::sleep_for(16ms);
        }
    }
private:
    void Update()
    {
        for(auto packet = client_->receive();packet!=nullptr;client_->deallocatePacket(packet),packet=client_->receive())
        {
            Hello h;
            if(!h.ParseFromArray(packet->body(), packet->bodyLength()))
            {
                cout << "protobuf parse fail\n";
            }
            else
            {
                cout << "update recv " << h.acc_name() << " " << h.passwd() << "\n";
            }
        }
    }
    bool stopped_;
    chat_client_ptr client_;
};

int main(int argc, char *argv[])
{
    // 有空去学习Linux的timerfd_create
    // 子线程负责网络, 主线程做update循环


    asio::io_context io_context;
    auto client = make_shared<chat_client>(io_context, tcp::endpoint(make_address_v4("127.0.0.1"), SERV_PORT));
    client->start();

    GameLoop g(client);
    g.Run();
    cout << "main exit..." << endl;
    return 0;
}
