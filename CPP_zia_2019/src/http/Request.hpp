/**
 *  @file     src/http/Request.hpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#pragma once

#include "api/sources/http/IRequest.hpp"

namespace zia::http {

    /** 
     * @brief A class which implements the IRequest interface.
     * This class design an http request according to the project API.
     */
    class Request : public api::http::IRequest {
    public:
        /** 
         * @brief Request default constructor.
         */
        Request();
        /** 
         * @brief Request destructor, set by default.
         */
        ~Request() final = default;

        /** 
         * @brief Clear the whole request.
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
         * @brief getMethod
         * @return api::String
         */
        inline api::String getMethod() const final
        {
            return _method;
        }


        /** 
         * @brief getUri
         * @return api::String
         */
        inline api::String getUri() const final
        {
            return _uri;
        }


        /*  <-------------------- Setters -------------------->  */

        /** 
         * @brief setBody
         * @return void
         * @param body : The new body of the request.
         */
        inline void setBody(const api::Buffer &body)
        {
            _body = body;
        }


        /** 
         * @brief setVersion
         * @return void
         * @param major : The major http version of the request.
         * @param minor : The minor http version of the request.
         */
        inline void setVersion(unsigned char major, unsigned char minor)
        {
            _version = major + '.' + minor;
        }


        /** 
         * @brief setMethod
         * @return void
         * @param method : The new method of the request.
         */
        inline void setMethod(const api::String &method) final
        {
            _method = method;
        }


        /** 
         * @brief setUri
         * @return void
         * @param uri : The new uri of the request.
         */
        inline void setUri(const api::String &uri) final
        {
            _uri = uri;
        }


    private:
        api::Headers _headers;
        api::Buffer _body;
        api::String _version;
        api::String _method;
        api::String _uri;
    };

}