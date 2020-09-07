/*
** EPITECH PROJECT, 2019
** Droid.hpp
** File description:
** droid header
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <string>
#include <iostream>

class DroidMemory
{
public:
    // Ctor / Dtor
    DroidMemory();
    ~DroidMemory();

    // Member methods
    DroidMemory &operator<<(const DroidMemory &mem);
    DroidMemory &operator>>(DroidMemory &mem);
    DroidMemory &operator+=(DroidMemory &mem);
    DroidMemory &operator+=(const size_t exp);
    DroidMemory operator+(const DroidMemory &mem) const;
    DroidMemory operator+(const size_t exp) const;

    // Getters
    size_t getFingerPrint() const;
    size_t getExp() const;

    // Setters
    void setFingerPrint(const size_t fp);
    void setExp(const size_t exp);
private:
    size_t _fingerPrint;
    size_t _exp;
};

#endif /* !DROIDMEMORY_HPP_ */
