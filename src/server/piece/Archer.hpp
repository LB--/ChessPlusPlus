#ifndef chesspp_server_piece_Archer_HeaderPlusPlus
#define chesspp_server_piece_Archer_HeaderPlusPlus

#include "server/board/Board.hpp"
#include "Piece.hpp"

namespace chesspp { namespace server
{
    namespace piece
    {
        class Archer
        : public virtual Piece
        {
        public:
            Archer(board::Board &b, Position_t const &pos, Suit_t const &s, Class_t const &pc);

        protected:
            virtual void calcTrajectory() override;
        };
    }
}}

#endif
