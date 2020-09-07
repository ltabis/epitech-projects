/**
 *  @file     src/http/Response.hpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#pragma once

#include "api/sources/http/IResponse.hpp"

namespace zia::http {

    /** 
     * @brief A class which implements the IResponse interface.
     * This class design an http response according to the project API.
     */
    class Response : public api::http::IResponse {
    public:
        /** 
         * @brief Response default constructor.
         */
        Response();
        /** 
         * @brief Response destructor, set by default.
         */
        ~Response() final = default;

        /** 
         * @brief Clear the whole response.
         */
        void clear() final;


        /*  <-------------------- Getters -------------------->  */

        /** 
         * @brief getHeaders
         * @return api::Headers &
         */
        inline api::Headers &getHeaders() final
        {
            return _headers;
        }

        /** 
         * @brief getHeaders
         * @return const api::Headers &
         */
        inline const api::Headers &getHeaders() const final
        {
            return _headers;
        }


        /** 
         * @brief getBody
         * @return api::Buffer &
         */
        inline api::Buffer &getBody() final
        {
            return _body;
        }

        /** 
         * @brief getBody
         * @return const api::Buffer &
         */
        inline const api::Buffer &getBody() const
        {
            return _body;
        }


        /** 
         * @brief getVersion
         * @return api::String
         */
        inline api::String getVersion() const
        {
            return _version;
        }


        /** 
         * @brief getStatus
         * @return int
         */
        inline int getStatus() const final
        {
            return _status;
        }


        /*  <-------------------- Setters -------------------->  */

        /** 
         * @brief setBody
         * @return void
         * @param body : The new body of the response.
         */
        inline void setBody(const api::Buffer &body)
        {
            _body = body;
        }


        /** 
         * @brief setVersion
         * @return void
         * @param major : The new major http version of the response.
         * @param minor : The new minor http version of the response.
         */
        inline void setVersion(unsigned char major, unsigned char minor)
        {
            _version = major + '.' + minor;
        }


        /** 
         * @brief setStatus
         * @return void
         * @param status : The new status of the response.
         */
        inline void setStatus(int status) final
        {
            _status = status;
        }


    private:
        api::Headers _headers;
        api::Buffer _body;
        api::String _version;
        int _status;
    };

}