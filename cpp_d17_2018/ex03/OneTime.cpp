/*
** EPITECH PROJECT, 2019
** OneTime.cpp
** File description:
** OneTime methods
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key) : _keyPos(0), _key(key) {}

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

void OneTime::encryptChar(char plainchar)
{
    char currentKey = 0;
    char currChar = 0;

    if (!std::isalpha(plainchar)) {
        _keyPos = _keyPos >= _key.size() ? 0 : _keyPos;
        _keyPos++;
        std::cout << plainchar;
        return;
    }
    _keyPos = _keyPos >= _key.size() ? 0 : _keyPos;
    currChar = plainchar >= 'a' && plainchar <= 'z' ?
               plainchar - 'a' : plainchar -'A';
    currentKey = _key[_keyPos] >= 'a' && _key[_keyPos] <= 'z' ?
                 _key[_keyPos] - 'a' : _key[_keyPos] - 'A';
    if (std::islower(plainchar))
        std::cout << (char)((currentKey + currChar) % 26 + 'a');
    else
        std::cout << (char)((currentKey + currChar) % 26 + 'A');
    _keyPos++;
}
void OneTime::decryptChar(char cipherchar)
{
    char currentKey = 0;
    char currChar = 0;

    if (!std::isalpha(cipherchar)) {
        _keyPos = _keyPos >= _key.size() ? 0 : _keyPos;
        _keyPos++;
        std::cout << cipherchar;
        return;
    }
    _keyPos = _keyPos >= _key.size() ? 0 : _keyPos;
    currChar = cipherchar >= 'a' && cipherchar <= 'z' ?
               cipherchar - 'a' : cipherchar -'A';
    currentKey = _key[_keyPos] >= 'a' && _key[_keyPos] <= 'z' ?
                 _key[_keyPos] - 'a' : _key[_keyPos] - 'A';
    if (std::islower(cipherchar)) {
        std::cout << (char)(modulo((currChar - currentKey), 26) + 'a');
    } else {
        std::cout << (char)(modulo((currChar - currentKey), 26) + 'A');
    }
    _keyPos++;
}
void OneTime::reset()
{
    _keyPos = 0;
}