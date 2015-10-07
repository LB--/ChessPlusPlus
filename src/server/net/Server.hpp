#ifndef chesspp_server_net_Server_HeaderPlusPlus
#define chesspp_server_net_Server_HeaderPlusPlus

#include <boost/asio.hpp>

#include <memory>
#include <cstdint>

namespace chesspp { namespace server
{
    namespace net
    {
        class Game;
        class Player;
        class Server final
        {
            struct Impl;
            std::unique_ptr<Impl> impl;

        public:
            Server(boost::asio::io_service &ios, std::uint16_t port);
            ~Server();

            void start();
            void stop();
        };
    }
}}

#endif
