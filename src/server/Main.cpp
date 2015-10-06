#include "common/Debug.hpp"

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

    //TODO
}
