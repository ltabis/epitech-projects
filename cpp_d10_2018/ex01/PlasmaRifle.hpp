/*
** EPITECH PROJECT, 2019
** AWeapon.hpp
** File description:
** 
*/

#ifndef PLASMARIFLE_HPP_
#define PLASMARIFLE_HPP_

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
    PlasmaRifle();
    ~PlasmaRifle();

    void attack() const override;
private:
};

#endif /* !PLASMARIFLE_HPP_ */
