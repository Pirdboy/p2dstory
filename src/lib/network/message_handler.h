#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

namespace p2d {

namespace network {

class Channel;

class MessageHandler
{
public:
    MessageHandler(){}
    virtual void handleSSMsg(Channel *pChannel, const char *msg, int length) = 0;
    virtual void handleCSMsg(Channel *pChannel, const char *msg, int length) = 0;
};

}


} // namespace p2d




#endif // MESSAGEHANDLER_H
