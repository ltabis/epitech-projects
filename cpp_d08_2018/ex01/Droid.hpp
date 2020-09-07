/*
** EPITECH PROJECT, 2019
** Droid.hpp
** File description:
** droid header
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include "DroidMemory.hpp"

class Droid
{
public:
    // Ctor / Dtor
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
    DroidMemory *getBattleData() const;

    // Setters
    void setId(std::string);
    void setEnergy(size_t energy);
    void setStatus(std::string *status);
    void setBattleData(DroidMemory *);
private:
    std::string _id;
    size_t _energy;
    const size_t _attack;
    const size_t _toughness;
    std::string *_status;
    DroidMemory *_battleData;
};

std::ostream &operator<<(std::ostream &stream, const Droid &droid);
std::ostream &operator<<(std::ostream &stream, const DroidMemory &mem);

#endif /* !DROID_HPP_ */
