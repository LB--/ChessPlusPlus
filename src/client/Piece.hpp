#ifndef chesspp_client_Piece_HeaderPlusPlus
#define chesspp_client_Piece_HeaderPlusPlus

#include "SFML.hpp"

#include <cstdint>

namespace chesspp { namespace client
{
    class Piece final
    {
    public:
        using Id_t = std::uint32_t;
    private:
        Id_t uid;
        //TODO: shared texture

    public:
        Piece() = delete;
        Piece(Id_t uid) noexcept
        : uid{uid}
        {
        }
        Piece(Piece const &from) noexcept
        : uid{from.uid}
        {
        }
        Piece(Piece &&from) noexcept
        : uid{from.uid}
        {
        }
        Piece const &operator=(Piece const &from) noexcept
        {
            uid = from.uid;
            return *this;
        }
        Piece const &operator=(Piece &&from) noexcept
        {
            uid = from.uid;
            return *this;
        }

        Id_t id() const noexcept
        {
            return uid;
        }
    };
    inline bool operator==(Piece const &a, Piece const &b) noexcept
    {
        return a.id() == b.id();
    }
    inline bool operator<(Piece const &a, Piece const &b) noexcept
    {
        return a.id() < b.id();
    }
}}

#endif
