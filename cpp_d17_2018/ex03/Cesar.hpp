/*
** EPITECH PROJECT, 2019
** Cesar.hpp
** File description:
** Cesar header
*/

#ifndef CESAR_HPP
#define CESAR_HPP

#include <string>
#include <iostream>
#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod
{
public:
    Cesar();

    void encryptChar(char) override;
    void decryptChar(char) override;
    void reset() override;

private:
    int _shift;
};


#endif /* !CESAR_HPP */
