#ifndef chesspp_server_net_Player_HeaderPlusPlus
#define chesspp_server_net_Player_HeaderPlusPlus

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
            ~Player();
        };
    }
}}

#endif
