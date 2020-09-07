/*
** EPITECH PROJECT, 2019
** Toy.cpp
** File description:
** toy methods
*/

#include "Toy.hpp"

Toy::Toy() : _type(BASIC_TOY), _name("toy"), _picture(Picture()) {}

Toy::Toy(ToyType type, const std::string &name, const std::string &file) :
        _type(type), _name(name), _picture(Picture(file)) {}

std::string Toy::getName() const
{
    return _name;
}

void Toy::setName(const std::string &name)
{
    _name = name;
}

bool Toy::setAscii(const std::string &file)
{
    return _picture.getPictureFromFile(file);
}

std::string Toy::getAscii() const
{
    return _picture.getPicture();
}

Toy::ToyType Toy::getType() const
{
    return _type;
}