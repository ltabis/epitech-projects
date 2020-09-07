/**
 *  @file     src/modules/logger/EasyLogger.hpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#pragma once

#include <unordered_map>
#include <functional>
#include <iostream>
#include "api/sources/module/ALogger.hpp"

namespace zia::mod {

    /** 
     * @brief A class wich implements the ALogger abstract class.
     * This class gives an example of basic but useful logger for other modules.
     */
    class EasyLogger : public api::module::ALogger {
    public:
        /** 
         * @brief EasyLogger default constructor.
         */
        EasyLogger();
        /** 
         * @brief EasyLogger destructor, set by default.
         */
        ~EasyLogger() final = default;

        /** 
         * @brief Display a message on an appropriated outpur, according to the level of significance of the message.
         * @param message : The message to log (output depends on level).
         * @param level : The level to which the message must be logged.
         */
        void log(const api::String &message, Level level) final;
 
 
        /*  <-------------------- Setters -------------------->  */
 
        /** 
         * @brief setConfig
         * @param config : The new config of the logger.
         */
        void setConfig(const api::JsonObject &config) final;

    private:
        /** 
         * @brief Display properly the message with some pretty colors.
         * @param header : The header of the message, which is a property of this logger.
         * @param message : The message to log.
         * @param color : The color of the header, which allows to distinguish logs according to their level.
         * @param s : The stream on which the message will be displayed (basically std::cout or std::cerr).
         */
        void displayWithColors(const api::String &header,
            const api::String &message, const api::String &color, std::ostream &s);

    private:
        std::unordered_map<Level, std::function<void (const api::String &message)>> _logCallbacks;
    };

}