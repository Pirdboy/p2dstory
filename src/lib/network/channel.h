#ifndef CHANNEL_H
#define CHANNEL_H

#include <asio.hpp>
#include <deque>

#include "packet.h"

using asio::ip::tcp;

namespace p2d {

namespace network {

class NetworkInterface;

class Channel
{
public:
    Channel(tcp::socket socket, NetworkInterface &net_interface);
    void run();
    void send(const Packet &packet);
private:
    void processPacket(const Packet &packet);
//    void doReadHeader();
//    void doReadBody();
//    void doWrite();

    tcp::socket socket_;
    NetworkInterface &net_interface_;
    Packet read_packet_;
    std::deque<Packet> send_packets_;

};

}

}


#endif // CHANNEL_H
