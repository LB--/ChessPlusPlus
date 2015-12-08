#ifndef chesspp_server_net_Player_HeaderPlusPlus
#define chesspp_server_net_Player_HeaderPlusPlus

#include <SFML/Network/TcpListener.hpp>

#include <memory>
#include <cstdint>

namespace chesspp { namespace server
{
    namespace net
    {
        class Game;
        class Server;
        class Player final
        {
            struct Impl;
            std::unique_ptr<Impl> impl;

        public:
            Player(sf::TcpListener &listener);
            Player(Player const &) = delete;
            Player(Player &&) noexcept;
            Player &operator=(Player const &) = delete;
            Player &operator=(Player &&) noexcept;
            ~Player();

            bool connected() const noexcept;
            void disconnect(/*TODO*/);
        };
    }
}}

#endif
