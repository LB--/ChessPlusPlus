#ifndef chesspp_client_config_ResourcesConfig_HeaderPlusPlus
#define chesspp_client_config_ResourcesConfig_HeaderPlusPlus

#include "common/config/Configuration.hpp"
#include "client/res/ResourceManager.hpp"

namespace chesspp { namespace client
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
            res::ResourceManager res;

        public:
            /**
             * \brief
             * Loads resource configuration from "config/chesspp/resources.json"
             */
            ResourcesConfig()
            : Configuration{"data/config/resources.json"}
            , res{*this}
            {
            }

            /**
             * \brief
             * Get the chesspp::res::ResourceManager
             * 
             * \return chesspp::res::ResourceManager
             */
            res::ResourceManager &resources() noexcept
            {
                return res;
            }
        };
    }
}}

#endif
