/*
** EPITECH PROJECT, 2019
** CHARACTER_HPP_
** File description:
** CHARACTER_HPP_
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <ostream>
#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character
{
public:
    Character(const std::string &name);
    ~Character();

    void recoverAP();
    void equip(AWeapon *weapon);
    void attack(AEnemy *enemy);
    const std::string &getName() const;
    std::string getWeaponName() const;
    bool checkAp();

    friend std::ostream &operator<<(std::ostream &os, const Character &character);

private:
    const std::string _name;
    int _ap;
    AWeapon *_curWeapon;
};

std::ostream &operator<<(std::ostream &, const Character &);

#endif /* !CHARACTER_HPP_ */
