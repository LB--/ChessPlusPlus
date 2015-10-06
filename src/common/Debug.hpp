#ifndef chesspp_common_Debug_HeaderPlusPlus
#define chesspp_common_Debug_HeaderPlusPlus

namespace chesspp { namespace common
{
    /**
     * \brief
     * Redirects std::clog, std::cerr, and std::cout to individual files, permanently.
     * 
     * Calling this more than once is harmless and has no effect.
     */
    void enableRedirection() noexcept;
}}

#endif
