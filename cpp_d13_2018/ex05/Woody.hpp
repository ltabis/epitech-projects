/*
** EPITECH PROJECT, 2019
** Buzz.hpp
** File description:
** Buzz header
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy
{
public:
    Woody(const std::string &);
    Woody(const std::string &, const std::string &);

    void speak(const std::string &) override;
    bool speak_es(const std::string &) override;
};

#endif /* !WOODY_HPP_ */
