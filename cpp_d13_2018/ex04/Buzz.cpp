/*
** EPITECH PROJECT, 2019
** Buzz.cpp
** File description:
** Buzz methods
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name) : Toy(BUZZ, name, "")
{
    _picture.setPicture("");
    _picture.getPictureFromFile("wuzz.txt");
}
Buzz::Buzz(const std::string &name, const std::string &file) : Toy(BUZZ, name, file) {}

void Buzz::speak(const std::string &state)
{
    std::cout << "BUZZ: " << _name << " \"" << state << "\"" << std::endl;
}