/**
 *  @file     src/Exception.hpp
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
#include "Color.hpp"

namespace zia {

    /** 
     * @brief A class which inherits from the std::exception class.
     * This class allows to throw exceptions designed for the zia project.
     */
    class Exception : public std::exception {
    public:
        /** 
         * @brief Exception destructor, set by default.
         */
        ~Exception() override = default;
        /** 
         * @brief Exception default constructor, which is deleted.
         */
        Exception() noexcept = delete;
        /** 
         * @brief Exception constructor with std::strings.
         * @param what : The description of the exception.
         * @param where : The optional origin of the exception.
         */
        explicit Exception(std::string what, std::string where = "") noexcept;
        /** 
         * @brief Exception constructor with const C-strings.
         * @param what : The description of the exception.
         * @param where : The optional origin of the exception.
         */
        explicit Exception(const char *what, const char *where = "") noexcept;
        /** 
         * @brief Exception copy constructor, set by default.
         * @param other : The other Exception to copy.
         */
        Exception(const Exception &other) = default;
        /** 
         * @brief operator= default overloading.
         * @return Exception &
         * @param other : The other Exception to copy.
         */
        Exception &operator=(const Exception &other) = default;

        /** 
         * @brief operator<<
         * @return friend std::ostream &
         * @param output : The stream where the exception will be displayed.
         * @param e : The exception to display.
         */
        friend std::ostream &operator<<(std::ostream &output, const Exception &e)
        {
            output << RED << typeid(e).name() << " caught : " << BLUE << e._what;
            if (!e._where.empty())
            {
                output << YELLOW << " from " << e._where;
            }
            output << RESET << std::endl;
            return output;
        }


        /*  <-------------------- Getters -------------------->  */

        /** 
         * @brief what
         * @return char const *
         */
        inline char const *what() const noexcept override
        {
            return _what.c_str();
        }

        /** 
         * @brief where
         * @return char const *
         */
        virtual inline char const *where() const noexcept
        {
            return _where.c_str();
        }

    protected:
        std::string _what;
        std::string _where;
    };

}

