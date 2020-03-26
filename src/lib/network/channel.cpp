#include "channel.h"

namespace network {

Channel::Channel(tcp::socket socket, NetworkInterface &net_interface)
    :socket_(std::move(socket)),net_interface_(net_interface)
{

}

}


