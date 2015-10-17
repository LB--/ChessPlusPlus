#include "Player.hpp"

#include <boost/asio.hpp>

namespace chesspp { namespace server
{
    namespace net
    {
        struct Player::Impl final
        {
            boost::asio::ip::tcp::socket client;
            boost::asio::io_service::strand strand;
        };
    }
}}
