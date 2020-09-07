/*
** EPITECH PROJECT, 2019
** AWeapon.hpp
** File description:
** 
*/

#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_

#include <iostream>
#include <string>

class  AWeapon
{
public:
    AWeapon(const std::string &name, int apcost, int damage);
    virtual ~AWeapon();
    const std::string &getName() const;
    int getAPCost() const;
    int getDamage() const;
    virtual void attack() const = 0;

    int get_dmg() const;

private:
    const std::string _name;
    const int _ap;
    int _dmg;
};

#endif /* !AWEAPON_HPP_ */
