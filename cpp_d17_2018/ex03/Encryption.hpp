/*
** EPITECH PROJECT, 2019
** Encryption.hpp
** File description:
** Encryption class
*/

#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <algorithm>
#include "IEncryptionMethod.hpp"
#include "OneTime.hpp"
#include "Cesar.hpp"

class Encryption
{
public:
    Encryption(IEncryptionMethod &method, void (IEncryptionMethod::*func)(char)) :
            _func(func), _method(method) {}

    void operator()(char);

    static void encryptString(IEncryptionMethod &, const std::string &);
    static void decryptString(IEncryptionMethod &, const std::string &);

private:
    void (IEncryptionMethod::*_func)(char);
    IEncryptionMethod &_method;
};

#endif /* !ENCRYPTION_HPP */
