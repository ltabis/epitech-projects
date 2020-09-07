/*
** EPITECH PROJECT, 2019
** Encryption.cpp
** File description:
** Encryption methods
*/

#include "Encryption.hpp"

void Encryption::operator()(char val)
{
    (_method.*_func)(val);
}

void Encryption::encryptString(IEncryptionMethod &encryptionMethod ,
                            const std::string &toEncrypt)
{
    Encryption e(encryptionMethod, &IEncryptionMethod::encryptChar);
    std::for_each(toEncrypt.begin(), toEncrypt.end(), e);
    std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod &encryptionMethod,
                            const std::string &toDecrypt)
{
    Encryption e(encryptionMethod, &IEncryptionMethod::decryptChar);
    std::for_each(toDecrypt.begin(), toDecrypt.end(), e);
    std::cout << std::endl;
}