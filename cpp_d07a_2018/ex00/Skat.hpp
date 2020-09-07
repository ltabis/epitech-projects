/*
** EPITECH PROJECT, 2019
** Skat.hpp
** File description:
** Skat header
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <string>
#include <iostream>

class Skat
{
public:
    // Ctor / Dtor
    Skat();
    Skat(const std::string &name, int stimPaks);
    ~Skat();

    // Member methods
    int &stimPaks();
    const std::string &name();
    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();
private:
    std::string _name;
    int _stimPaks;
};

#endif /* !SKAT_HPP_ */
