/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main function
*/

#include "temp.hpp"

Temp::Temp() : _value(0), _name("Celsius") {}
Temp::~Temp() {}

void Temp::to_celsius(double far)
{
    this->_value = 5.0 / 9.0 * (far - 32);
    this->_name = "Celsius";
    this->display();
}

void Temp::to_fahrenheit(double cel)
{
    this->_value = (cel * (9.0 / 5.0)) + 32;
    this->_name = "Fahrenheit";
    this->display();
}

void Temp::display()
{
    std::cout << std::setw(16) << std::fixed <<
    std::setprecision(3) << this->_value << std::setw(16) <<
    this->_name << std::endl;
}

double Temp::get_value()
{
    return (this->_value);
}

int main(void)
{
    std::string::size_type sz;
    std::string input_line;
    double input = 0.0f;
    Temp conv;

    while (std::cin && std::getline(std::cin, input_line)) {
        input = std::stof(input_line, &sz);
        if (input_line.find("Celsius") != std::string::npos)
            conv.to_fahrenheit(input);
        else if (input_line.find("Fahrenheit") != std::string::npos)
            conv.to_celsius(input);
    }
    return 0;
}
