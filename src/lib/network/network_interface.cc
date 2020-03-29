#include "network_interface.h"
#include "channel.h"
#include <iostream>
#include <cstdio>

using namespace std;

namespace p2d {

namespace network {

NetworkInterface::NetworkInterface(asio::io_context &io_context)
    : io_context_(io_context), acceptor_(io_context), message_handler_ptr_(nullptr)
{

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
                                   //
                                   // TODO: objectPool
                                   Channel* c = new Channel(std::move(socket),this);
                                   this->registerChannel(this->peer_endpoint_, c);
                                   c->run();
                               }
                               else
                               {

                               }
                           });
}

inline void NetworkInterface::set_message_handler(MessageHandler *pHandler)
{
    message_handler_ptr_ = pHandler;
}

void NetworkInterface::registerChannel(const tcp::endpoint &addr, Channel *pChannel)
{
    address_channel_map_.insert(pair<tcp::endpoint,Channel*>(addr, pChannel));
}

MessageHandler *NetworkInterface::message_handler()
{
    return message_handler_ptr_;
}

} // namespace network

} // namespace p2d
