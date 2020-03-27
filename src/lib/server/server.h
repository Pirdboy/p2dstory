#ifndef SERVER_H
#define SERVER_H

#include "network/message_handler.h"

namespace p2d {

namespace server {

class Server : public network::MessageHandler
{
public:
    Server();
};

} // namespace server

} // namespace p2d


#endif // SERVER_H
