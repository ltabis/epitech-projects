/*
** EPITECH PROJECT, 2019
** ex06.hpp
** File description:
** ex06 header
*/

#ifndef EX06_HPP
#define EX06_HPP

#include <string>
#include <iostream>
#include <sstream>

template <typename T, typename U = T>
class Tuple
{
public:
    std::string toString() const
    {
        std::string s = "[TUPLE [";
        s += checkTypeT();
        s += "] [";
        s += checkTypeU();
        s += "]]";
        return s;
    }

    T a;
    U b;
private:
    std::string checkTypeT() const
    {
        std::string c = "";
        std::ostringstream out;
        out.precision(1);
        if (typeid(T) == typeid(int)) {
            out << a;
            return "int:" + out.str();
        } else if (typeid(T) == typeid(float)) {
            out << std::fixed << a;
            return "float:" + out.str() + "f";
        } else if (typeid(T) == typeid(std::string)) {
            c = "string:\"";
            c += a;
            c += "\"";
            return c;
        }
        return "???";
    }
    std::string checkTypeU() const
    {
        std::string c = "";
        std::ostringstream out;
        out.precision(1);
        if (typeid(U) == typeid(int)) {
            out << b;
            return "int:" + out.str();
        } else if (typeid(U) == typeid(float)) {
            out << std::fixed << b;
            return "float:" + out.str() + "f";
        } else if (typeid(U) == typeid(std::string)) {
            c = "string:\"";
            c += b;
            c += "\"";
            return c;
        }
        return "???";
    }
};
#endif /* !EX06_HPP */
