#ifndef NETPACKET_H
#define NETPACKET_H


class NetPacket
{
public:
    NetPacket();
    static const int HEADER_LENGTH = 4;
    static const int MAX_BODY_LENGTH = 20480;
    const char *data() const;
    char *data();
    int length() const;
    const char *body() const;
    char *body();
    int bodyLength() const;
    void bodyLength(int newLength);
    bool decodeHeader();
    void encodeHeader();
private:
    char data_[HEADER_LENGTH + MAX_BODY_LENGTH];
    int bodyLength_;
};

#endif // NETPACKET_H
