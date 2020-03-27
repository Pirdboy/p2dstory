#include "channel.h"
#include "network_interface.h"

namespace p2d {

namespace network {

Channel::Channel(tcp::socket socket, NetworkInterface &net_interface)
    :socket_(std::move(socket)),net_interface_(net_interface)
{
    //net_interface.registerChannel(socket_.local_endpoint(), this);
}

void Channel::run()
{

}

void Channel::send(const Packet &packet)
{
//    bool writing_in_progress = !write_packets_.empty();
//    write_packets_.push_back(packet);
//    if(!writing_in_progress)
//    {
//        doWrite();
//    }
}

} // namespace network

}  // namespace p2d
