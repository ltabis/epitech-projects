/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#ifndef EX02_HPP
#define EX02_HPP

#include <iostream>

template<typename T>
T min (const T p1, const T p2)
{
    std::cout << "template min" << std::endl;
    if (p1 == p2)
        return p1;
    else if (p1 > p2)
        return p2;
    return p1;
}

template<typename T>
T templateMin (const T *p1, int size)
{
    T smallest = p1[0];

    for (int i = 0; i + 1 < size; i++) {
        if (min(p1[i], p1[i + 1]) == p1[i])
            smallest = p1[i];
        else
            smallest = p1[i + 1];
    }
    return smallest;
}

int min (int p1, int p2)
{
    std::cout << "non-template min" << std::endl;
    if (p1 == p2)
        return p1;
    else if (p1 > p2)
        return p2;
    return p1;
}


int nonTemplateMin (const int *p1, int size)
{
    int smallest = p1[0];

    for (int i = 0; i + 1 < size; i++) {
        if (min(p1[i], p1[i + 1]) == p1[i])
            smallest = p1[i];
        else
            smallest = p1[i + 1];
    }
    return smallest;
}

#endif /* !EX02_HPP */
