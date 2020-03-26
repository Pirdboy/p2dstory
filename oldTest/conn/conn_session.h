#ifndef GATEWAYSESSION_H
#define GATEWAYSESSION_H

#include "asio.hpp"
#include "netpacket.h"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <memory>
#include <deque>

using asio::ip::tcp;


class ConnServer;

class ConnSession : public std::enable_shared_from_this<ConnSession>
{
public:
    ConnSession(tcp::socket socket, ConnServer &server);
    void start();
    void writePacket(const NetPacket &packet);
    boost::uuids::uuid uuid() const;
private:
    void doReadHeader();
    void doReadBody();
    void doWrite();
    void dealPacket();
private:
    tcp::socket socket_;
    ConnServer &server_;
    NetPacket read_packet_;
    std::deque<NetPacket> write_packets_;
    boost::uuids::uuid uuid_;  // 固定128位的uuid
};

#endif // GATEWAYSESSION_H
