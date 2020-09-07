/*
** EPITECH PROJECT, 2019
** Phaser.cpp
** File description:
** phaser methods
*/

#include "Phaser.hpp"

// Ctor / Dtor
Phaser::Phaser() : Phaser(20, REGULAR) {}
Phaser::Phaser(const int maxAmmo, const AmmoType type) : _maxAmmo(maxAmmo), _sounds(Sounds())
{
    for (auto i = 0; i < maxAmmo; i++)
        this->_ammoTypes.push_back(type);
    _defaultType = type;
}
Phaser::~Phaser() {}

void Phaser::fire()
{
    std::string sound;

    if (this->_ammoTypes.size() == this->Empty)
        std::cout << "Clip empty, please reload" << std::endl;
    else {
        if (this->_ammoTypes.back() == REGULAR)
            sound = this->_sounds.Regular;
        else if (this->_ammoTypes.back() == REGULAR)
            sound = this->_sounds.Plasma;
        else
            sound = this->_sounds.Rocket;
        std::cout << sound << std::endl;
        this->_ammoTypes.pop_back();
    }
}

void Phaser::ejectClip()
{
    this->_ammoTypes.clear();
}

void Phaser::changeType(AmmoType newType)
{
    std::string types[3] = {"regular", "plasma", "rocket"};

    std::cout << "Switching ammo to type: " << types[newType] << std::endl;
    this->_defaultType = newType;
}

void Phaser::reload()
{
    std::cout << "Reloading..." << std::endl;
    this->_ammoTypes.clear();
    for (unsigned int i = 0; i < this->_maxAmmo; i++)
        this->_ammoTypes.push_back(this->_defaultType);
}

void Phaser::addAmmo(AmmoType type)
{
    if (this->_ammoTypes.size() == this->_maxAmmo)
        std::cout << "Clip full" << std::endl;
    else
        this->_ammoTypes.push_back(type);
}

int Phaser::getCurrentAmmos() const
{
    return(this->_ammoTypes.size());
}
