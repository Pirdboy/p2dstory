#ifndef PACKET_H
#define PACKET_H

#include <cstdint>
#include <vector>

namespace p2d {

namespace network {

class Packet
{
public:
    Packet(){}
    static const uint16_t HEADER_LENGTH = 4;
    static const uint16_t MSGID_LENGTH = 2;
    static const uint16_t MAX_BODY_LENGTH = 32768;
//    const char *data() const
//    {
//        return data_;
//    }
//    const char *body() const
//    {
//        return data_ + HEADER_LENGTH;
//    }

//    int body_length() const
//    {
//        return body_length_;
//    }
//    void set_body_length(int len)
//    {
//        body_length_ = len;
//    }
    //    bool decodeHeader()
    //    {

    //    }
    //    void encodeHeader()
    //    {

    //    }
private:
    //char data_[HEADER_LENGTH + MAX_BODY_LENGTH];

    int body_length_;
    uint16_t msg_id;

    std::vector<uint8_t> data_; // 注意维护buffer_size

    // 参考KBEngine memorystream.h, packet.h, tcp_packet.h
    // 注意resize就行
};

}

}



#endif // PACKET_H
