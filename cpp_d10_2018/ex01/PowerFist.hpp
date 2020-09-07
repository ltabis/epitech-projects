/*
** EPITECH PROJECT, 2019
** AWeapon.hpp
** File description:
** 
*/

#ifndef POWERFIST_HPP_
#define POWERFIST_HPP_

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
    PowerFist();
    ~PowerFist();

    void attack() const override;
private:
};

#endif /* !POWERFIST_HPP_ */
