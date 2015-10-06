#ifndef chesspp_server_config_ResourcesConfig_HeaderPlusPlus
#define chesspp_server_config_ResourcesConfig_HeaderPlusPlus

#include "common/config/Configuration.hpp"

namespace chesspp { namespace server
{
    namespace config
    {
        /**
         * \brief
         * Holds configuration for resources (graphics, fonts, etc)
         */
        class ResourcesConfig
        : public common::config::Configuration
        {
        public:
            /**
             * \brief
             * Loads resource configuration from "config/chesspp/resources.json"
             */
            ResourcesConfig()
            //TODO
            : Configuration{"data/config/chesspp/resources.json"}
            {
            }
        };
    }
}}

#endif
