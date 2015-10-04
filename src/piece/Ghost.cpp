#include "Ghost.hpp"

namespace chesspp
{
    namespace piece
    {
        static auto GhostRegistration = board::Board::registerPieceClass
        (
            "Ghost",
            [](board::Board &b, board::Board::Position_t const &p, board::Board::Suit const &s)
            -> board::Board::Pieces_t::value_type
            {
                return board::Board::Pieces_t::value_type(new Ghost(b, p, s, "Ghost"));
            }
        );

        Ghost::Ghost(board::Board &b, Position_t const &pos_, Suit_t const &s_, Class_t const &pc)
        : Piece{b, pos_, s_, pc}
        {
        }

        void Ghost::calcTrajectory()
        {
            //Ghosts can move anywhere at any time, and can posess pieces by overlapping them
            for(Position_t::value_type x = 0; x < board.config.boardWidth(); ++x)
            {
                for(Position_t::value_type y = 0; y < board.config.boardHeight(); ++y)
                {
                    addTrajectory({x, y});
                }
            }
            //Ghosts can only capture once they posess
            addCapturing(pos);
        }
    }
}
