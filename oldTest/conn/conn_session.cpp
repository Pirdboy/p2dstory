#include "conn_session.h"
#include "conn_server.h"
#include "cs.pb.h"
#include <cstdio>

using namespace std;

ConnSession::ConnSession(tcp::socket socket, ConnServer &server)
    :socket_(std::move(socket)), server_(server), uuid_(boost::uuids::random_generator()())
{

}

void ConnSession::start()
{
    server_.join(shared_from_this());
    doReadHeader();
}

void ConnSession::writePacket(const NetPacket &packet)
{
    bool writing_in_progress = !write_packets_.empty();
    write_packets_.push_back(packet);
    if(!writing_in_progress)
    {
        doWrite();
    }
}

boost::uuids::uuid ConnSession::uuid() const
{
    return uuid_;
}

void ConnSession::doReadHeader()
{
    // 后续用容器保存shared_ptr，避免引用计数的加减，会有不少开销
    // 但要先取消该session相关asio事件
    auto self(shared_from_this());
    asio::async_read(socket_, asio::buffer(read_packet_.data(), NetPacket::HEADER_LENGTH),
                     [this, self](std::error_code ec, size_t /*len*/)
                     {
                         if(!ec && read_packet_.decodeHeader())
                         {
                             doReadBody();
                         }
                         else
                         {
                             // 日志记录
                         }
                     });
}

void ConnSession::doReadBody()
{
    printf("Read Bodylength: %d\n",read_packet_.bodyLength());
    auto self(shared_from_this());
    asio::async_read(socket_, asio::buffer(read_packet_.body(), read_packet_.bodyLength()),
                     [this, self](std::error_code ec, size_t /*len*/)
                     {
                         if(!ec)
                         {
                             dealPacket();
                             doReadHeader();
                         }
                         else
                         {
                             // 日志记录错误
                             printf("gateway session: some error\n");
                         }
                     });

}

void ConnSession::doWrite()
{
    auto self(shared_from_this());
    asio::async_write(socket_, asio::buffer(
                                   write_packets_.front().data(),
                                   write_packets_.front().length()),
                      [this, self](std::error_code ec, size_t/*len*/)
                      {
                          if(!ec)
                          {
                              write_packets_.pop_front();
                              if(!write_packets_.empty())
                              {
                                  doWrite();
                              }
                          }
                          else
                          {
                              // 日志记录错误
                          }

                      });
}

void ConnSession::dealPacket()
{
    // 日志输出read_packet的内容
    //printf("recv bodyLength:%d\n", read_packet_.bodyLength());

    // 测试protobuf
    Hello h;
    if(h.ParseFromArray(read_packet_.body(), read_packet_.bodyLength()))
    {
        cout << "recv Hello:{" << h.acc_name() << ", " << h.passwd() << "}\n";
    }
    else
    {
        printf("protobuf parse fail...\n");
    }

    NetPacket packet;
    h.set_acc_name("服务器");
    h.set_passwd("22222222");
    h.SerializeToArray(packet.body(), h.ByteSizeLong());
    packet.bodyLength(h.ByteSizeLong());
    packet.encodeHeader();
    this->writePacket(packet);
}
