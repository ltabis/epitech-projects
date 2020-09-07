/*
** EPITECH PROJECT, 2019
** Droid.hpp
** File description:
** droid header
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <string>
#include <iostream>

class Droid
{
public:
    // Ctor / Dtor
    Droid();
    Droid(const Droid &cpy);
    Droid(std::string serial);
    ~Droid();

    // Member methods
    void operator=(const Droid &droid);
    bool operator==(const Droid &droid) const;
    bool operator!=(const Droid &droid) const;
    Droid &operator<<(size_t &energy);

    // Geters
    std::string getId() const;
    std::string getSerial() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    std::string *getStatus() const;

    // Setters
    void setId(std::string);
    void setEnergy(size_t energy);
    void setStatus(std::string *status);
private:
    std::string _id;
    size_t _energy;
    const size_t _attack;
    const size_t _toughness;
    std::string *_status;
};

std::ostream &operator<<(std::ostream &stream, const Droid &droid);

#endif /* !DROID_HPP_ */
