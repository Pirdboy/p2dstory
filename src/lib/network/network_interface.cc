#include "network_interface.h"
#include "channel.h"
#include <iostream>
#include <cstdio>

using namespace std;

namespace network {

NetworkInterface::NetworkInterface(asio::io_context &io_context, uint16_t port)
    : io_context_(io_context), acceptor_(io_context)
{
    this->initialize(port);
}

void NetworkInterface::initialize(uint16_t port)
{
    tcp::endpoint address(tcp::v4(), port);  // INADDR_ANY
    acceptor_.open(address.protocol());
    acceptor_.set_option(tcp::acceptor::reuse_address(true));
    acceptor_.bind(address);
    acceptor_.listen(5);
    acceptor_.async_accept(peer_endpoint_,
                           [this](std::error_code ec, tcp::socket socket)
                           {
                               if(!ec)
                               {

                               }
                               else
                               {

                               }
                           });
}


}

