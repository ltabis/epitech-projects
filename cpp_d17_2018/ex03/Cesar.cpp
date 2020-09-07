/*
** EPITECH PROJECT, 2019
** Cesar.cpp
** File description:
** Cesar methods
*/

#include "Cesar.hpp"

Cesar::Cesar() : _shift(3) {}

void Cesar::encryptChar(char plainchar)
{
    if (!std::isalpha(plainchar)) {
        _shift++;
        std::cout << plainchar;
        return;
    }
    if (std::islower(plainchar))
        std::cout << char((plainchar + _shift - 'a') % 26 + 'a');
    else
        std::cout << char((plainchar+ _shift - 'A') % 26 + 'A');
    _shift++;
}
void Cesar::decryptChar(char cipherchar)
{
    if (!std::isalpha(cipherchar)) {
        _shift++;
        std::cout << cipherchar;
        return;
    }
    _shift = _shift > 26 ? 1 : _shift;
    if (std::islower(cipherchar))
        std::cout << char((cipherchar + (26 - _shift) - 'a') % 26 + 'a');
    else
        std::cout << char((cipherchar + (26 - _shift) - 'A') % 26 + 'A');
    _shift++;
}
void Cesar::reset()
{
    _shift = 3;
}