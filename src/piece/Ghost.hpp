#ifndef chesspp_piece_Ghost_HeaderPlusPlus
#define chesspp_piece_Ghost_HeaderPlusPlus

#include "board/Board.hpp"
#include "piece/Piece.hpp"

namespace chesspp
{
    namespace piece
    {
        class Ghost
        : public virtual Piece
        {
        public:
            Ghost(board::Board &b, Position_t const &pos, Suit_t const &s, Class_t const &pc);

        protected:
            virtual void calcTrajectory() override;
        };
    }
}

#endif
