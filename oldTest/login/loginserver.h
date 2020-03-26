#ifndef LOGINSERVER_H
#define LOGINSERVER_H

#include <asio.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <set>
#include <memory>
#include <map>

#include "login_server_session.h"

using asio::ip::tcp;

// Player与智能指针
// 1. 智能指针本身内存是普通指针的两倍
// 2. 好处主要还是减少内存泄漏的机会
// 3. 使用时要用weak_ptr
// 4. 智能指针能否支持自定义内存分配器???

using LoginServerSessionPtr = std::shared_ptr<LoginServerSession>;

class LoginServer
{
public:
    LoginServer(asio::io_context &io_context);
    void Start();
    void join(LoginServerSessionPtr session);
private:
    asio::io_context &io_context_;
    tcp::acceptor acceptor_;
    tcp::socket socket_;
    void doAccept();
//    std::map<boost::uuids::uuid, PlayerPtr> players_;
    std::map<boost::uuids::uuid, LoginServerSessionPtr> sessions_;
};

#endif // LOGINSERVER_H
