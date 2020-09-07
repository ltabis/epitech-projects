/*
** EPITECH PROJECT, 2019
** Buzz.cpp
** File description:
** Buzz methods
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name) : Toy(WOODY, name, "")
{
    _picture.setPicture("");
    _picture.getPictureFromFile("woody.txt");
}
Woody::Woody(const std::string &name, const std::string &file) :
        Toy(WOODY, name, file) {}

bool Woody::speak(const std::string &state)
{
    std::cout << "WOODY: " << _name << " \"" << state << "\"" << std::endl;
    return true;
}

bool Woody::speak_es(const std::string &state)
{
    (void)state;
    _errType = Error::SPEAK;
    return false;
}