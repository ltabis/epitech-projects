/*
** EPITECH PROJECT, 2019
** AENEMY_HPP_
** File description:
** AENEMY_HPP_
*/

#ifndef AENEMY_HPP_
#define AENEMY_HPP_

#include <string>
#include <iostream>

class AEnemy
{
public:
    AEnemy(int hp, const std:: string &type);
    virtual ~AEnemy();

    void takeDamage(int damage);
    const std::string &getType() const;
    int getHP() const;

    void setHp(const int _hp);

protected:
    int _hp;
    const std::string _type;
};


#endif /* !AENEMY_HPP_ */
