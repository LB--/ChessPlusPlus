#ifndef chesspp_client_Board_HeaderPlusPlus
#define chesspp_client_Board_HeaderPlusPlus

#include "Piece.hpp"
#include "Action.hpp"
#include "common/util/Position.hpp"
#include "SFML.hpp"

#include <boost/bimap.hpp>
#include <boost/bimap/set_of.hpp>
#include <boost/bimap/multiset_of.hpp>

#include <cstdint>

namespace chesspp { namespace client
{
    class Board final
    {
    public:
        using Position_t = common::util::Position<std::uint32_t>;
        using Pieces_t  = boost::bimap<boost::bimaps::multiset_of<Position_t>, boost::bimaps::set_of<Piece>>;
        using Actions_t = boost::bimap<boost::bimaps::multiset_of<Position_t>, boost::bimaps::set_of<Action>>;
    private:
        Pieces_t pieces;
        Actions_t actions;

    public:
        Board() = default;

        double cellSizeX() const noexcept;
        double cellSizeY() const noexcept;
        Position_t::value_type cellCountX() const noexcept;
        Position_t::value_type cellCountY() const noexcept;

        void draw(sf::RenderTarget &target);

        auto piecesAt(Position_t const &pos) noexcept
        {
            return pieces.left.equal_range(pos);
        }
        auto piecesAt(Position_t const &pos) const noexcept
        {
            return pieces.left.equal_range(pos);
        }
        Position_t positionOf(Piece const &p) const;

        auto actionsAt(Position_t const &pos) noexcept
        {
            return actions.left.equal_range(pos);
        }
        auto actionsAt(Position_t const &pos) const noexcept
        {
            return actions.left.equal_range(pos);
        }
        Position_t positionOf(Action const &a) const;
    };

    inline double sizeX(Board const &b) noexcept { return b.cellSizeX() * b.cellCountX(); }
    inline double sizeY(Board const &b) noexcept { return b.cellSizeY() * b.cellCountY(); }

    inline bool valid(Board const &b, Board::Position_t const &pos) noexcept
    {
        return pos.isWithin(Board::Position_t::Origin(), {b.cellCountX(), b.cellCountY()});
    }
}}

#endif
