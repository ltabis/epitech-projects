/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
** Character header
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Mage.hpp"

class Priest : public Mage
{
public:
    Priest(const std::string &, int);
    ~Priest();

    int RangeAttack();
    void Heal();
private:
};

#endif /* !PRIEST_HPP_ */
