#include "common/Debug.hpp"
#include "net/Server.hpp"

/**
 * \brief
 * Entry point of the server.
 * 
 * \param nargs argument count, not used.
 * \param args arguments, not used.
 */
int main(int nargs, char const *const *args)
{
#ifdef CHESSPP_REDIRECT_OUTPUT
    chesspp::common::enableRedirection();
#endif

    chesspp::server::net::Server server {20702};

    server.start();
}
