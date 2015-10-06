#include "app/Application.hpp"
#include "app/StartMenuState.hpp"
#include "common/Debug.hpp"

#include <iostream>
#include <typeinfo>
#include <cstdlib>

/**
 * \brief
 * Entry point of the client.
 * 
 * Sets up the application window and then passes control to chesspp::client::app::StartMenuState
 * 
 * \param nargs argument count, not used.
 * \param args arguments, not used.
 */
int main(int nargs, char const *const *args)
{
#ifdef CHESSPP_REDIRECT_OUTPUT
    chesspp::common::enableRedirection();
#endif

    try
    {
        sf::RenderWindow disp
        {
            sf::VideoMode(640, 640),
            "ChessPlusPlus",
            sf::Style::Close
        };
        chesspp::client::app::Application app {disp};
        app.changeState<chesspp::client::app::StartMenuState>(std::ref(app), std::ref(disp));
        return app.execute();
    }
    catch(std::exception &e)
    {
        std::cerr << typeid(e).name() << " caught in main: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    std::clog << "Exiting normally from main" << std::endl;
}
