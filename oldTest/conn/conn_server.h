#ifndef SERVER_H
#define SERVER_H

#include "asio.hpp"
#include "conn_session.h"
#include <set>
#include <memory>
#include <map>

#define SERV_PORT 11000
#define LOGIN_SERV_PORT 11002

using asio::ip::tcp;
using namespace std;

using ConnSessionPtr = std::shared_ptr<ConnSession>;

class ConnServer
{
public:
    ConnServer(asio::io_context &io_context, const tcp::endpoint &endpoint);
    void start();
    void join(ConnSessionPtr session);
private:
    void doAccept();
    tcp::acceptor acceptor_;
    tcp::socket loginSvrSock_;
    std::map<boost::uuids::uuid, ConnSessionPtr> sessions_;


    // 后续专门维护一个PlayerList的容器，负责创建、删除、查找
//    map<unsigned int, Player *> m_PlayerMap;
//    map<uint64_t, Player *> m_PlayerGuidMap;
};

#endif // SERVER_H
