#ifndef chesspp_server_piece_King_HeaderPlusPlus
#define chesspp_server_piece_King_HeaderPlusPlus

#include "server/board/Board.hpp"
#include "Piece.hpp"

namespace chesspp { namespace server
{
    namespace piece
    {
        class King
        : public virtual Piece
        {
        public:
            King(board::Board &b, Position_t const &pos, Suit_t const &s, Class_t const &pc);

        protected:
            virtual void calcTrajectory() override;
        };
    }
}}

#endif
