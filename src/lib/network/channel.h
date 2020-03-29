#ifndef CHANNEL_H
#define CHANNEL_H

#include <asio.hpp>
#include <deque>
#include <system_error>

#include "tcp_packet.h"

using asio::ip::tcp;

namespace p2d {

namespace network {

class NetworkInterface;

class Channel
{
public:
    Channel(tcp::socket socket, NetworkInterface *pNetworkInterface);
    void run();
    tcp::socket *socket();
private:
    void onPacketReceived(const TCPPacket* pPacket, std::error_code ec);
    tcp::socket socket_;
    NetworkInterface *network_interface_ptr_;
    TCPPacket read_packet_;
    std::deque<TCPPacket*> send_packets;

};

}

}


#endif // CHANNEL_H
