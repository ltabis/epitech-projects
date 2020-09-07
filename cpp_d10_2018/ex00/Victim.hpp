/*
** EPITECH PROJECT, 2019
** Sorcerer.hpp
** File description:
** Sorcerer
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <iostream>
#include <string>

class Victim
{
public:
    // Ctor / Dtor
    Victim(const std::string &);
    ~Victim();

    // Member methods
    virtual void getPolymorphed() const;

    // Getters
    const std::string getName() const;
private:
    const std::string _name;
};

std::ostream &operator<<(std::ostream &, const Victim &);

#endif /* !VICTIM_HPP_ */
