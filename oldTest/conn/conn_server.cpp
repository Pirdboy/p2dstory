#include "conn_server.h"



using namespace std;

ConnServer::ConnServer(asio::io_context &io_context,
               const tcp::endpoint &endpoint)
    : acceptor_(io_context, endpoint), loginSvrSock_(io_context)
{
}

void ConnServer::start()
{
    acceptor_.set_option(tcp::acceptor::reuse_address(true));
    doAccept();
}

void ConnServer::join(ConnSessionPtr session)
{
    sessions_.insert(std::pair<boost::uuids::uuid, ConnSessionPtr>(session->uuid(), session));
}

void ConnServer::doAccept()
{
    printf("doAccept...\n");
    acceptor_.async_accept(
        [this](std::error_code ec, tcp::socket socket) {
            if(!ec)
            {
                printf("conn_server 有客户端连接了...\n\n");
                make_shared<ConnSession>(std::move(socket), *this)->start();
            }
            doAccept();
        });
}


int main(int argc, char *argv[])
{
    asio::io_context io_context;
    ConnServer svr(io_context, tcp::endpoint(tcp::v4(), SERV_PORT));
    svr.start();
    io_context.run();
    return 0;
}
