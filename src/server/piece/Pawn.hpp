#ifndef chesspp_server_piece_Pawn_HeaderPlusPlus
#define chesspp_server_piece_Pawn_HeaderPlusPlus

#include "server/board/Board.hpp"
#include "Piece.hpp"

namespace chesspp { namespace server
{
    namespace piece
    {
        class Pawn
        : public virtual Piece
        {
            bool en_passant = true;
            common::util::Direction facing;

        public:
            Pawn(board::Board &b, Position_t const &pos, Suit_t const &s, Class_t const &pc, common::util::Direction const &face);

            virtual void tick(Position_t const &p) override;

        protected:
            virtual void calcTrajectory() override;
        };
    }
}}

#endif
