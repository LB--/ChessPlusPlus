#include "Server.hpp"

namespace chesspp { namespace server
{
    namespace net
    {
        struct Server::Impl final
        {
            boost::asio::io_service &ios;
            boost::asio::ip::tcp::acceptor acceptor;

            Impl(boost::asio::io_service &ios, std::uint16_t port)
            : ios(ios)
            , acceptor{ios, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v6(), port)}
            {
            }
        };
        Server::Server(boost::asio::io_service &ios, std::uint16_t port)
        : impl{std::make_unique<Impl>(std::ref(ios), port)}
        {
        }
        Server::~Server() = default;

        void Server::start()
        {
            //
        }
        void Server::stop()
        {
            //
        }
    }
}}
