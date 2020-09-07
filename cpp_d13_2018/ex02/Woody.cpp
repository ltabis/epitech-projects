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