#ifndef CPP_ZIA_2019_API_MODULE_IMODULE_HPP
#define CPP_ZIA_2019_API_MODULE_IMODULE_HPP

#include "../Types.hpp"

namespace api::module {

    class IModule {
    public:
        using Type = enum {
            LOGGER,
            NETWORK,
            HTTP
        };

        virtual ~IModule() = default;

        // Return the type of the module, should be checked before dynamic_cast.
        virtual Type getType() const = 0;
        // Update configuration of the module. The Json Object contains only the configuration specific to the module.
        virtual void setConfig(const api::JsonObject &config) = 0;
    };

}

#endif /* CPP_ZIA_2019_API_MODULE_IMODULE_HPP */
