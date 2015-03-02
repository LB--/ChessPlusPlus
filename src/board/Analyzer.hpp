#ifndef ChessPlusPlus_Board_Analyzer_HeaderPlusPlus
#define ChessPlusPlus_Board_Analyzer_HeaderPlusPlus

#include "board/Board.hpp"

#include <functional>
#include <map>
#include <memory>
#include <string>

namespace chesspp
{
    namespace board
    {
        /**
         * \brief
         * Base class for board analyzers, which determine end conditions for boards.
         * 
         * A board analyzer is responsible for handling end conditions and other special states
         * such as check, checkmate, winning/losing, ties, etc. Analyzers are only required to
         * tell whether a board is in an end state, but may also provide additional info (e.g.
         * check).
         * 
         * Analyzers are not tied to any one board - instead, one analyzer can be constructed
         * with parameters and then be reused for multiple boards.
         */
        class Analyzer
        {
        public:
            using Factories_t = std::map<std::string, std::function<std::unique_ptr<Analyzer> (config::BoardConfig const &)>>;
            virtual ~Analyzer() = default;

            /**
             * \brief
             * Register a new type of board analyzer.
             * 
             * This should be called via assignment to a global variable in the source file of
             * the analyzer implementation.
             * 
             * \param type The unique type of the analyzer.
             * \param ctor The function used to construct new instances of the analyzer.
             * \return The registration receipt, to be stored in the global variable.
             */
            static auto registerAnalyzer(Factories_t::key_type const &type, Factories_t::mapped_type ctor)
            -> Factories_t::iterator
            {
                return factories().insert({type, ctor}).first;
            }
            /**
             * \brief
             * Construct a new board analyzer from a chesspp::config::BoardConfig
             * 
             * \param type The unique type of the analyzer.
             * \param conf The chesspp::config::BoardConfig instance, only used temporarily.
             * \return The newly constructed analyzer, or `nullptr` if no analyzer is associated
             * with the given type.
             */
            static auto newAnalyzer(Factories_t::key_type const &type, config::BoardConfig const &conf)
            -> Factories_t::mapped_type::result_type
            {
                if(factories().find(type) != factories().end())
                {
                    return factories().at(type)(conf);
                }
                return {nullptr};
            }

            /**
             * \brief
             * Determines if a board is in an end state.
             * 
             * \param board The Board to determine end state for.
             * \return `true` if the board is in an end state, `false` otherwise.
             */
            virtual bool isEnded(Board const &board) const = 0;

        private:
            static Factories_t &factories() noexcept
            {
                static Factories_t f;
                return f;
            }
        };
    }
}

#endif
