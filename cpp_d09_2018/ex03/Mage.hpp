/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
** Character header
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage : public Character
{
public:
    Mage(const std::string &, int);
    ~Mage();

    int CloseAttack();
    virtual int RangeAttack();
    void RestorePower();
private:
};
#endif /* !MAGE_HPP_ */
