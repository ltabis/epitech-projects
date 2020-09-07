/**
 *  @file     src/modules/http/HttpModule.hpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#pragma once

#include <memory>
#include "AHttp.hpp"

namespace zia::mod {

    /** 
     * @brief A class which implements the AHttp abstract class.
     * It is a basic implementation of an http module, which serve as an example.
     */
    class HttpModule : public api::module::AHttp {
    public:
        /** 
         * @brief HttpModule default constructor.
         */
        HttpModule();
        /** 
         * @brief HttpModule destructor, set by default.
         */
        ~HttpModule() = default;

        /** 
         * @brief Read the request and write the response, send and receive packets.
         * @return bool
         * @param connection : The tcp connection to handle.
         */
        bool handle(Connection &connection) final;


        /*  <-------------------- Setters -------------------->  */

        /** 
         * @brief setLogger
         * @return void
         * @param logger : The new logger of the module.
         */
        inline void setLogger(api::module::ALogger *logger) final
        {
            _logger.reset(logger);
        }


        /** 
         * @brief setConfig
         * @param config : The new config of the module got from a json file.
         */
        void setConfig(const api::JsonObject &config) final;

    private:
        std::shared_ptr<api::module::ALogger> _logger;
    };

}