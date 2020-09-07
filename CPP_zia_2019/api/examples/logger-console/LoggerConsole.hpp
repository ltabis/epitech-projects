#ifndef API_ZIA_LOGGERCONSOLE_HPP
#define API_ZIA_LOGGERCONSOLE_HPP

#include <iostream>
#include "../../sources/module/ALogger.hpp"

class LoggerConsole : public api::module::ALogger {
public:
    ~LoggerConsole() override = default;
    LoggerConsole();

    void setConfig(const api::JsonObject &config) override;
    void log(const api::String &message, Level lvl) override;

private:
    static void print(std::ostream &stream, const api::String &message, const api::String &color = "");
    bool _debug;
};


#endif /* API_ZIA_LOGGERCONSOLE_HPP */
