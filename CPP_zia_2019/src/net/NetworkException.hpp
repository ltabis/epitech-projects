/**
 *  @file     src/net/NetworkException.hpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#pragma once

#include <iostream>
#include <exception>
#include <string>
#include "src/Color.hpp"
#include "src/Exception.hpp"

namespace zia::net {

    /** 
     * @brief A class which inherits from the zia Exception class.
     * This class allows to throw exceptions designed for the network.
     */
    class NetworkException : public zia::Exception {
    public:
        /** 
         * @brief NetworkException destructor, set by default.
         */
        ~NetworkException() override = default;
        /** 
         * @brief NetworkException default constructor, which is deleted.
         */
        NetworkException() noexcept = delete;
        /** 
         * @brief NetworkException constructor with std::strings.
         * @param what : The description of the exception.
         * @param where : The optional origin of the exception.
         */
        explicit NetworkException(std::string what, std::string where = "") noexcept;
        /** 
         * @brief NetworkException constructor with const C-strings.
         * @param what : The description of the exception.
         * @param where : The optional origin of the exception.
         */
        explicit NetworkException(const char *what, const char *where = "") noexcept;
        /** 
         * @brief NetworkException copy constructor, set by default.
         * @param other : The other NetworkException to copy.
         */
        NetworkException(const NetworkException &other) = default;
        /** 
         * @brief operator= default overloading.
         * @return NetworkException &
         * @param other : The other NetworkException to copy.
         */
        NetworkException &operator=(const NetworkException &other) = default;

    };
}

