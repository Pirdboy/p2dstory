#include "netpacket.h"
#include <cstring>
//#include <string.h>
#include <arpa/inet.h>

NetPacket::NetPacket() : bodyLength_(0)
{
}

const char *NetPacket::data() const
{
    return data_;
}

char *NetPacket::data()
{
    return data_;
}

int NetPacket::length() const
{
    return HEADER_LENGTH + bodyLength_;
}

const char *NetPacket::body() const
{
    return data_ + HEADER_LENGTH;
}

char *NetPacket::body()
{
    return data_ + HEADER_LENGTH;
}

int NetPacket::bodyLength() const
{
    return bodyLength_;
}

void NetPacket::bodyLength(int newLength)
{
    bodyLength_ = newLength;
    if (bodyLength_ > MAX_BODY_LENGTH)
    {
        bodyLength_ = MAX_BODY_LENGTH;
    }
}

bool NetPacket::decodeHeader()
{
    memcpy(&bodyLength_, data_, HEADER_LENGTH);
    return true;
}

void NetPacket::encodeHeader()
{
    // asio不用考虑字节序问题
    memcpy(data_, &bodyLength_, HEADER_LENGTH);
}
