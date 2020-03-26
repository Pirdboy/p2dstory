#ifndef LOGINSERVERSESSION_H
#define LOGINSERVERSESSION_H

#include "asio.hpp"
#include "netpacket.h"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <memory>
#include <deque>

using asio::ip::tcp;

class LoginServer;

class LoginServerSession : public std::enable_shared_from_this<LoginServerSession>
{
public:
    LoginServerSession(tcp::socket socket, LoginServer &server);
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
    LoginServer &server_;
    NetPacket read_packet_;
    std::deque<NetPacket> write_packets_;
    boost::uuids::uuid uuid_;  // 固定128位的uuid
};

#endif // LOGINSERVERSESSION_H
