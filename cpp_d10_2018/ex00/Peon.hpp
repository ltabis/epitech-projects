/*
** EPITECH PROJECT, 2019
** Peon.hpp
** File description:
** Peon
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include "Victim.hpp"

class Peon : public Victim
{
public:
    Peon(const std::string &);
    ~Peon();

    void getPolymorphed() const final;
private:
};

#endif /* !PEON_HPP_ */
