/*
** EPITECH PROJECT, 2019
** temp.hpp
** File description:
** temp header
*/

#ifndef TEMP_HPP_
#define TEMP_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Temp {
public:
    // Init
    Temp();
    ~Temp();

    // Member methods
    void to_celsius(double val);
    void to_fahrenheit(double val);
    double get_value();
    void display();

private:
    // Properties
    double _value;
    std::string _name;
};

#endif /* !TEMP_HPP_ */
