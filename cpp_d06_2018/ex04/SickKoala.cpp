/*
** EPITECH PROJECT, 2019
** SickKoala.cpp
** File description:
** main file
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name) : _name(name) {}
SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->_name <<
    ": Kreooogg!! I'm cuuuured!" << std::endl;
}

std::string SickKoala::getName()
{
    return (this->_name);
}

void SickKoala::poke()
{
    std::cout << "Mr." << this->_name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string s)
{
    if (s.compare("Buronzand") == 0) {
        std::cout << "Mr." << this->_name <<
        ": And you'll sleep right away!" << std::endl;
        return (true);
    }
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (s.compare("mars") == 0) {
        std::cout << "Mr." << this->_name <<
        ": Mars, and it kreogs!" << std::endl;
        return (true);
    }
    std::cout << "Mr." << this->_name << ": Goerkreog!" << std::endl;
    return (false);
}

void SickKoala::overDrive(std::string s)
{
    const std::string t = "1337!";
    std::string::size_type find = 0;

    while ((find = s.find("Kreog!", find)) != std::string::npos) {
        s.replace(find, 6, t);
        find += t.size();
    }
    std::cout << "Mr." << this->_name << ": " << s << std::endl;
}
