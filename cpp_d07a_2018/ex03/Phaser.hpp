/*
** EPITECH PROJECT, 2019
** Phaser.hpp
** File description:
** phaser
*/

#ifndef PHASER_HPP_
#define PHASER_HPP_

#include "Sounds.hpp"

class Phaser
{
public:
    enum AmmoType {REGULAR, PLASMA, ROCKET};

    // Ctor / Dtor
    Phaser();
    Phaser(const int maxAmmo, const AmmoType type);
    ~Phaser();

    // Member methods
    void fire();
    void ejectClip();
    void changeType(AmmoType newType);
    void reload();
    void addAmmo(AmmoType type);
    int getCurrentAmmos() const;
private:
    static const int Empty = 0;
    unsigned int _maxAmmo;
    Sounds _sounds;
    std::vector<AmmoType> _ammoTypes;
    AmmoType _defaultType;
};

#endif /* !PHASER_HPP_ */
