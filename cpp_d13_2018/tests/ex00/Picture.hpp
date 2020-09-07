/*
** EPITECH PROJECT, 2019
** Picture.hpp
** File description:
** Picture header
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <fstream>
#include <iostream>
#include <string>

class Picture
{
public:
    // Ctor / Dtor
    Picture();
    Picture(const std::string &);
    virtual ~Picture();
    int catFileContent();

    std::string getPicture() const;
    void setPicture(const std::string &str);

    // Member methods
    bool getPictureFromFile(const std::string &);
private:
    std::string _data;
};

#endif /* !PICTURE_HPP_ */
