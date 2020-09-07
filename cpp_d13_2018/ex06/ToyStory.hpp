/*
** EPITECH PROJECT, 2019
** ToyStory.hpp
** File description:
** ToyStory class
*/

#ifndef TOYSTORY_HPP
#define TOYSTORY_HPP

#include "Toy.hpp"

class ToyStory
{
public:
    static void tellMeAStory(const std::string &, Toy &,
    bool (Toy::*)(const std::string &), Toy &,
    bool (Toy::*)(const std::string &));

    static void checkToyToUse(Toy &, Toy &,
                       std::string &, unsigned int,
                       bool (Toy::*)(const std::string &),
                       bool (Toy::*)(const std::string &),
                        std::string &);
    static bool changePicture(const std::string &, Toy &,
    std::string &);
};


#endif //TOYSTORY_HPP
