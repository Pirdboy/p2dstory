#include "channel.h"
#include "network_interface.h"
#include <vector>
#include <functional>
#include "message_handler.h"

using namespace std;

namespace p2d {

namespace network {

Channel::Channel(tcp::socket socket, NetworkInterface *pNetworkInterface)
    : socket_(std::move(socket)),
      network_interface_ptr_(pNetworkInterface),
      read_packet_(this)
{

}

void Channel::run()
{
    auto handler = std::bind(&Channel::onPacketReceived, this, std::placeholders::_1, std::placeholders::_2);
    read_packet_.asyncRead(handler);
//read_packet_.asyncRead([this](const TCPPacket* packetPtr, std::error_code ec)
//                       {
//                           this->onPacketReceived(packetPtr, ec);
//                       });
}


inline tcp::socket *Channel::socket()
{
    return &socket_;
}

void Channel::onPacketReceived(const TCPPacket *pPacket, std::error_code ec)
{
    if(nullptr != network_interface_ptr_)
    {
        auto messageHandler = network_interface_ptr_->message_handler();
        switch(pPacket->message_type())
        {
            case MessageType::CSMsg:
                messageHandler->handleCSMsg(this, (const char*)pPacket->body(), pPacket->body_size());
                break;
            case MessageType::SSMsg:
                messageHandler->handleSSMsg(this, (const char*)pPacket->body(), pPacket->body_size());
                break;
            default:
                break;
        }
    }
}

} // namespace network

}  // namespace p2d
