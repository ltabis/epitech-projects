/*
** EPITECH PROJECT, 2019
** SickKoala.hpp
** File description:
** header ex02
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <string>
#include <iostream>
#include <algorithm>

class SickKoala {
public:
    // Ctor
    SickKoala(std::string);
    ~SickKoala();

    // Member method
    void poke();
    bool takeDrug(std::string s);
    void overDrive(std::string s);
private:
    std::string _name;
};

#endif /* !SICKKOALA_HPP_ */
