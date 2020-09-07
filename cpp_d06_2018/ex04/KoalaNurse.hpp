/*
** EPITECH PROJECT, 2019
** SickKoala.hpp
** File description:
** header ex02
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include "SickKoala.hpp"
#include <string>
#include <iostream>
#include <fstream>

class KoalaNurse {
public:
    // Ctor
    KoalaNurse(int);
    ~KoalaNurse();

    // Member method
    void giveDrug(std::string Drug, SickKoala *koala);
    std::string readReport(std::string filename);
    void timeCheck();

private:
    int _id;
    char _isWorking;
};

#endif /* !KOALANURSE_HPP_ */
