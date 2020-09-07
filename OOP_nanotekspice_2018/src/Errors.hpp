/*
** EPITECH PROJECT, 2019
** Errors.hpp
** File description:
** Errors class
*/

#ifndef Errors_HPP
#define Errors_HPP

#include <iostream>

namespace err {

    class Errors : std::exception {
    public:
        static bool displayError(const std::string &err)
        {
            std::cerr << err << std::endl;
            return false;
        }
    };

}

#endif /* !Errors_HPP */
