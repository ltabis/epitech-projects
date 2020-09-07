/*
** EPITECH PROJECT, 2019
** OneTime.hpp
** File description:
** OneTime header
*/

#ifndef ONETIME_HPP
#define ONETIME_HPP

#include <string>
#include <iostream>
#include "IEncryptionMethod.hpp"

class OneTime : public IEncryptionMethod
{
public:
    explicit OneTime(const std::string &key);

    void encryptChar(char) override;
    void decryptChar(char) override;
    void reset() override;

private:
    unsigned int _keyPos;
    const std::string _key;
};

#endif /* !ONETIME_HPP */
