#include "login_server_session.h"
#include "loginserver.h"

using namespace std;

LoginServerSession::LoginServerSession(tcp::socket socket, LoginServer &server)
    :socket_(std::move(socket)),server_(server)
{

}

void LoginServerSession::start()
{
    server_.join(shared_from_this());
    doReadHeader();
}

void LoginServerSession::writePacket(const NetPacket &packet)
{
    bool writing_in_progress = !write_packets_.empty();
    write_packets_.push_back(packet);
    if(!writing_in_progress)
    {
        doWrite();
    }
}

boost::uuids::uuid LoginServerSession::uuid() const
{
    return uuid_;
}

void LoginServerSession::doReadHeader()
{
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

void LoginServerSession::doReadBody()
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

void LoginServerSession::doWrite()
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

void LoginServerSession::dealPacket()
{
    // 来自其他server的消息
    // 该消息可能需要LoginServer处理，也可能自行处理即可

    // 先mock用户登录的数据
}
