/*
** EPITECH PROJECT, 2019
** find.hpp
** File description:
** find header
*/

#ifndef FIND_HPP
#define FIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator do_find(T &obj, int toFind)
{
    return std::find(obj.begin(), obj.end(), toFind);
}
#endif /* !FIND_HPP */
