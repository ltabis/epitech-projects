/*
** EPITECH PROJECT, 2019
** Buzz.hpp
** File description:
** Buzz header
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy
{
public:
    Buzz(const std::string &);
    Buzz(const std::string &, const std::string &);

    void speak(const std::string &state) override;
    bool speak_es(const std::string &state) override;
};

#endif /* !BUZZ_HPP_ */
