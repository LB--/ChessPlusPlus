#ifndef ChessPlusPlus_Board_TraditionalAnalyzer_HeaderPlusPlus
#define ChessPlusPlus_Board_TraditionalAnalyzer_HeaderPlusPlus

#include "board/Analyzer.hpp"

#include <map>

namespace chesspp
{
    namespace board
    {
        class TraditionalAnalyzer
        : public virtual Analyzer
        {
        public:
            virtual bool isEnded(Board const &board) const override;
            /**
             * \brief
             * Gets the chesspp::piece::King pieces in check.
             * 
             * The map key is the King in check, and the value is the movement that would
             * result in checkmate.
             * 
             * \param board The board to analyze for check conditions.
             * \return The King pieces in check.
             */
            virtual std::multimap<Board::Pieces_t::const_iterator, Board::Movements_t::const_iterator> getChecks(Board const &board) const;
        };
    }
}

#endif
