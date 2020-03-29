#ifndef TCPPACKET_H
#define TCPPACKET_H

#include <vector>
#include <cstdint>
#include <functional>
#include <system_error>
#include <asio.hpp>
#include <common/types.h>

using asio::ip::tcp;

namespace p2d {

namespace network {

enum class MessageType : uint8
{
    CSMsg = 0,
    SSMsg = 1
};

class TCPPacket;

using TCPPacketReceivedHandler = std::function<void(const TCPPacket*, std::error_code)>;

/*
 * TCP数据流分包
 * -----------------------------------------------------------
 * | header(body_size 4 byte) | msgType(1 byte) | body...... |
 * -----------------------------------------------------------
 */

// TODO:让tcp_packet_reader和tcp_packet_sender负责收和发
class TCPPacket
{
public:
    static const int FRAGMENT_HEADER_SIZE = 4;
    static const int FRAGMENT_MSGTYPE_SIZE = 1;
    TCPPacket(uint8* data, int size, MessageType msgType);
    int size() const noexcept;
    int body_size() const noexcept;
    uint8* data();
    const uint8* data() const;
    const uint8* body() const;
    MessageType message_type() const noexcept;
private:
    std::vector<uint8> data_;

};

//class TCPPacket
//{
//public:
//    TCPPacket(Channel *pChannel);
//    TCPPacket(Channel *pChannel, uint8_t* data, int size, MessageType msgType);
//    int size() const noexcept;
//    int body_size() const noexcept;
//    uint8_t* data();
//    const uint8_t* data() const;
//    const uint8_t* body() const;
//    MessageType message_type() const noexcept;
//    void asyncRead(TCPPacketReceivedHandler handler);
//private:
//    void asyncReadFragmentHeader();
//    void asyncReadFragmentMsgAndBody();
//private:
//    Channel *channel_ptr_;
//    int body_size_;
//    MessageType message_type_;
//    std::vector<uint8_t> data_;
//    TCPPacketReceivedHandler received_handler_;
//    static const int fragment_header_size = 4;
//    static const int fragment_msg_size = 1;
//};

} // namespace network

} // namespace p2d



#endif // TCPPACKET_H
