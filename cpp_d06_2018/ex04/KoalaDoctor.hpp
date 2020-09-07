/*
** EPITECH PROJECT, 2019
** KoalaD.hpp
** File description:
** header ex02
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include "KoalaNurse.hpp"

class KoalaDoctor {
public:
    // Ctor
    KoalaDoctor(std::string name);
    ~KoalaDoctor();

    // Member method
    void diagnose(SickKoala *);
    void timeCheck();
private:
    std::string _name;
    char _isWorking;
};

#endif /* !KOALADOCTOR_HPP_ */
