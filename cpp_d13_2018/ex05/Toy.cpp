/*
** EPITECH PROJECT, 2019
** Toy.cpp
** File description:
** toy methods
*/

#include "Toy.hpp"

Toy::Toy() : _type(BASIC_TOY), _name("toy"), _picture(Picture()), _errType(Error::UNKNOWN) {}
Toy::Toy(const Toy &pic) :
        _type(pic.getType()), _name(pic.getName()),
        _picture(Picture(pic.getPicture())), _errType(Error::UNKNOWN) {}
Toy::Toy(ToyType type, const std::string &name, const std::string &file) :
        _type(type), _name(name), _picture(Picture(file)), _errType(Error::UNKNOWN) {}
Toy::~Toy() {}
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
    if (_picture.getPictureFromFile(file) == false) {
        _errType = Error::PICTURE;
        return false;
    }
    return true;
}

std::string Toy::getAscii() const
{
    return _picture.getPicture();
}

Toy::ToyType Toy::getType() const
{
    return _type;
}

Picture Toy::getPicture() const
{
    return _picture;
}

Toy &Toy::operator=(const Toy &toy)
{
    _picture = toy.getPicture();
    _name = toy.getName();
    return *this;
}

Toy &Toy::operator<<(const std::string &str)
{
    _picture.setPicture(str);
    return *this;
}

void Toy::speak(const std::string &state)
{
    std::cout << _name << " \"" << state << "\"" << std::endl;
}

bool Toy::speak_es(const std::string &state)
{
    std::cout << _name << " senorita \"" << state << "\" senorita" << std::endl;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Toy &toy)
{
    os << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return os;
}

// Error class

std::string Toy::Error::what() const
{
    if (type == Error::PICTURE)
        return "bad new illustration";
    else if (type == Error::SPEAK)
        return "wrong mode";
    return "";
}

std::string Toy::Error::where() const
{
    if (type == Error::PICTURE)
        return "setAscii";
    else if (type == Error::SPEAK)
        return "speak_es";
    return "";
}

Toy::Error Toy::getLastError() const
{
    Toy::Error err;

    err.setErrType(*this);
    return err;
}