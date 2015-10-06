#ifndef chesspp_client_app_ChessPlusPlusState_HeaderPlusPlus
#define chesspp_client_app_ChessPlusPlusState_HeaderPlusPlus

#include "client/Board.hpp"
#include "AppState.hpp"
#include "Application.hpp"

#include <boost/optional.hpp>

#include <set>

namespace chesspp { namespace client
{
    namespace app
    {
        /**
         * \brief
         * The AppState class for the state of the chess gameplay.
         * 
         * This class handles user-interaction by manipulating the chesspp::Board
         * directly.
         */
        class ChessPlusPlusState
        : public AppState
        {
            Application &app;
            config::ResourcesConfig &res_config;
            Board board;

            boost::optional<Piece> selected;
            Board::Position_t p;

        public:
            /**
             * \brief
             * Construct from the Application and sf::RenderWindow to be used.
             * 
             * \param app The Application owning this instance, must outlive this instance.
             * \param display The sf::RenderWindow use during onRender(), must outlive this
             * instance.
             */
            ChessPlusPlusState(Application &app, sf::RenderWindow &display);

            /**
             * \brief
             * Renders the chessboard, all chess pieces, and any highlighted moves.
             */
            virtual void onRender() override;

            /**
             * \brief
             * Allows the player to exit to the main menu by pressing escape.
             */
            virtual void onKeyPressed(sf::Keyboard::Key key, bool alt, bool control, bool shift, bool system) override;
            /**
             * \brief
             * Updates which highlighted moves are visible.
             */
            virtual void onMouseMoved(int x, int y) override;
            /**
             * \brief
             * Currently does nothing.
             */
            virtual void onLButtonPressed(int x, int y) override;
            /**
             * \brief
             * Selects or deselects pieces, or moves a selected piece to the clicked position.
             */
            virtual void onLButtonReleased(int x, int y) override;
        };
    }
}}

#endif
