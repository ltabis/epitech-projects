/*
** EPITECH PROJECT, 2019
** Picture.cpp
** File description:
** Picture methods
*/

#include "Picture.hpp"

Picture::Picture() : _data("") {}
Picture::Picture(const Picture &pic) : _data(pic.getPicture()) {}
Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}
Picture::~Picture() {}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::string line = "";
    std::ifstream myfile;

    _data = "";
    myfile.open(file);
    if (myfile.is_open()) {
        while (std::getline(myfile, line))
            _data += (line + "\n");
        myfile.close();
        return true;
    } else
        _data = "ERROR";
    return false;
}

std::string Picture::getPicture() const
{
    return _data;
}

void Picture::setPicture(const std::string &str)
{
    _data = str;
}

Picture &Picture::operator=(const Picture &pic)
{
    _data = pic._data;
    return *this;
}
