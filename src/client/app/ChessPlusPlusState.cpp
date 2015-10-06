#include "ChessPlusPlusState.hpp"

#include "StartMenuState.hpp"
#include "common/util/Utilities.hpp"

#include <iostream>
#include <algorithm>

namespace chesspp { namespace client
{
    namespace app
    {
        ChessPlusPlusState::ChessPlusPlusState(Application &app_, sf::RenderWindow &disp)
        : AppState(disp)                    //can't use {}
        , app(app_)                         //can't use {}
        , res_config(app.resourcesConfig()) //can't use {}
        {
        }

        void ChessPlusPlusState::onRender()
        {
            board.draw(display);
        }

        void ChessPlusPlusState::onKeyPressed(sf::Keyboard::Key key, bool /*alt*/, bool /*control*/, bool /*shift*/, bool /*system*/)
        {
            if(key == sf::Keyboard::Escape)
            { //Exit to menu screen
                return app.changeState<StartMenuState>(std::ref(app), std::ref(display));
            }
        }
        void ChessPlusPlusState::onMouseMoved(int x, int y)
        {
            p.x = static_cast<Board::Position_t::value_type>(x/board.cellSizeX());
            p.y = static_cast<Board::Position_t::value_type>(y/board.cellSizeY());
        }
        void ChessPlusPlusState::onLButtonPressed(int x, int y)
        {
            //TODO
        }
        void ChessPlusPlusState::onLButtonReleased(int x, int y)
        {
            if(!valid(board, p)) return;
            if(!selected)
            {
                auto pieces = board.piecesAt(p);
                if(pieces.first != pieces.second)
                {
                    //TODO: don't just select the first one
                    selected = pieces.first->second;
                }
            }
            else
            {
                auto actions = board.actionsAt(p);
                if(actions.first != actions.second)
                {
                    //TODO: don't just select the first one
                    //TODO: netcode
                }
                selected = boost::none; //deselect
            }
        }
    }
}}
