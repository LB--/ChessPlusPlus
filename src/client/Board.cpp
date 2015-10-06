#include "Board.hpp"

#include <stdexcept>

namespace chesspp { namespace client
{
    double Board::cellSizeX() const noexcept
    {
        //TODO
        return 80.0;
    }
    double Board::cellSizeY() const noexcept
    {
        //TODO
        return 80.0;
    }
    auto Board::cellCountX() const noexcept
    -> Position_t::value_type
    {
        //TODO
        return 8;
    }
    auto Board::cellCountY() const noexcept
    -> Position_t::value_type
    {
        //TODO
        return 8;
    }

    void Board::draw(sf::RenderTarget &target)
    {
        //TODO
        target.clear();
    }

    auto Board::positionOf(Piece const &p) const
    -> Position_t
    {
        auto it = pieces.right.find(p);
        if(it == pieces.right.end())
        {
            throw std::invalid_argument{"Given piece is not on this board"};
        }
        return it->second;
    }
    auto Board::positionOf(Action const &a) const
    -> Position_t
    {
        auto it = actions.right.find(a);
        if(it == actions.right.end())
        {
            throw std::invalid_argument{"Given action is not on this board"};
        }
        return it->second;
    }
}}
