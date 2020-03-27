#include <asio.hpp>
#include <map>
#include <cstdint>
#include <asio.hpp>

using asio::ip::tcp;

namespace p2d {

namespace network {
// ChannelMap的key暂时先用tcp::endpoint, 后续更换
// 可以研究下Endpoint用map和unordered_map哪个更快,写程序测试

class Channel;
class MessageHandler;

class NetworkInterface
{
public:
    NetworkInterface(asio::io_context &io_context);
    void set_message_handler(MessageHandler *mh);
    void registerChannel(const tcp::endpoint& addr, Channel *pChannel);
private:
    void initialize(uint16_t port);
    using ChannelMap = std::map<tcp::endpoint, Channel*>;
    ChannelMap address_channel_map_;
    asio::io_context &io_context_;
    tcp::acceptor acceptor_;
    tcp::endpoint peer_endpoint_;
    MessageHandler *message_handler_;

private:
    // 一些测试方法
};

}

}

