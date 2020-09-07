/*
** EPITECH PROJECT, 2019
** Sorcerer.hpp
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include "Victim.hpp"

class Sorcerer
{
public:
    // Ctor / Dtor
    Sorcerer(const std::string &, const std::string &);
    ~Sorcerer();

    // Member methods
    void polymorph(const Victim &) const;

    // Getters
    const std::string getName() const;
    const std::string getTitle() const;
private:
    const std::string _name;
    const std::string _title;
};

std::ostream &operator<<(std::ostream &, const Sorcerer &);

#endif /* !SORCERER_HPP_ */
