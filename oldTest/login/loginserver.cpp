#include "loginserver.h"


#define LISTEN_PORT 12000

using namespace std;

LoginServer::LoginServer(asio::io_context &io_context)
    :io_context_(io_context), acceptor_(io_context), socket_(io_context)
{

}

void LoginServer::Start()
{
    tcp::endpoint endpoint(tcp::v4(), LISTEN_PORT);
    acceptor_.open(endpoint.protocol());
    acceptor_.bind(endpoint);
    acceptor_.set_option(tcp::acceptor::reuse_address(true));
    io_context_.run();
}

void LoginServer::join(LoginServerSessionPtr session)
{
    sessions_.insert(std::pair<boost::uuids::uuid, LoginServerSessionPtr>(session->uuid(), session));
}

void LoginServer::doAccept()
{
    acceptor_.async_accept(
        [this](std::error_code ec, tcp::socket socket)
        {
            if(!ec)
            {
                // 处理会话
                make_shared<LoginServerSession>(std::move(socket), *this)->start();
            }
            else
            {

            }
            doAccept();
        });
}


int main(int argc, char *argv[])
{
    asio::io_context io_context;
    LoginServer loginServer(io_context);
    loginServer.Start();


    return 0;
}
