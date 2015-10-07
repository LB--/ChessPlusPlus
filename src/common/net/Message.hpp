#ifndef chesspp_common_net_Message_HeaderPlusPlus
#define chesspp_common_net_Message_HeaderPlusPlus

namespace chesspp { namespace common
{
    namespace net
    {
        class Message
        {
            virtual ~Message() = 0;
        };
        inline Message::~Message() = default;
    }
}}

#endif
