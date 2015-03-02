#include "board/TraditionalAnalyzer.hpp"

#include "piece/Piece.hpp"
#include "piece/King.hpp"

namespace chesspp
{
    namespace board
    {
        static auto TraditionalAnalyzerRegistration = Analyzer::registerAnalyzer
        (
            "Traditional",
            [](config::BoardConfig const &)
            -> std::unique_ptr<Analyzer>
            {
                return std::unique_ptr<Analyzer>{new TraditionalAnalyzer};
            }
        );

        bool TraditionalAnalyzer::isEnded(Board const &board) const
        {
            bool found = false;
            for(auto const &p : board)
            {
                if(dynamic_cast<piece::King const *>(p.get()))
                {
                    if(found)
                    {
                        return false;
                    }
                    found = true;
                }
            }
            return true;
        }
        auto TraditionalAnalyzer::getChecks(Board const &board) const
        -> std::multimap<Board::Pieces_t::const_iterator, Board::Movements_t::const_iterator>
        {
            std::multimap<Board::Pieces_t::const_iterator, Board::Movements_t::const_iterator> checks;
            //
            return checks;
        }
    }
}
