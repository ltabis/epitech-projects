/*
** EPITECH PROJECT, 2019
** ex04.hpp
** File description:
** ex04 header
*/

#ifndef EX04_HPP
#define EX04_HPP

template<typename T>
bool equal(const T &t1, const T &t2)
{
    return t1 == t2;
}

template<typename T>
class Tester
{
public:
    bool equal(const T &t1, const T &t2) {return t1 == t2;}
};

#endif /* !EX04_HPP */
