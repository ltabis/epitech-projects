/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
** Character header
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Character.hpp"

class Priest : public Character
{
public:
    Priest(const std::string &, int);
    ~Priest();

    int CloseAttack();
    int RangeAttack();
    void RestorePower();
    void Heal();
private:
};
#endif /* !PRIEST_HPP_ */
