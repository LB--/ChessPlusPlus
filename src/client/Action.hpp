#ifndef chesspp_client_Action_HeaderPlusPlus
#define chesspp_client_Action_HeaderPlusPlus

#include <cstdint>

namespace chesspp { namespace client
{
    class Action final
    {
    public:
        using Id_t = std::uint32_t;
    private:
        Id_t uid;

    public:
        Id_t id() const noexcept
        {
            return uid;
        }
    };
    inline bool operator==(Action const &a, Action const &b) noexcept
    {
        return a.id() == b.id();
    }
    inline bool operator<(Action const &a, Action const &b) noexcept
    {
        return a.id() < b.id();
    }
}}

#endif
