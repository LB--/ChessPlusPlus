#ifndef chesspp_server_net_Game_HeaderPlusPlus
#define chesspp_server_net_Game_HeaderPlusPlus

#include <memory>
#include <cstdint>

namespace chesspp { namespace server
{
    namespace net
    {
        class Player;
        class Server;
        class Game final
        {
            struct Impl;
            std::unique_ptr<Impl> impl;

        public:
            ~Game();
        };
    }
}}

#endif
