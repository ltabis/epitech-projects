#ifndef CPP_ZIA_2019_API_MODULE_ALOGGER_HPP
#define CPP_ZIA_2019_API_MODULE_ALOGGER_HPP

#include "../Types.hpp"
#include "IModule.hpp"

namespace api::module {

    class ALogger : public IModule {
    public:
        using Level = enum {
            LEVEL_FATAL,
            LEVEL_ERROR,
            LEVEL_WARNING,
            LEVEL_INFO,
            LEVEL_DEBUG
        };

        virtual ~ALogger() override = default;

        Type getType() const final {return IModule::LOGGER;}

        virtual void log(const String &message, Level lvl) = 0;
        void log(const String &message) {log(message, LEVEL_INFO);}
    };

}

#endif /* CPP_ZIA_2019_ALOGGER_HPP */
