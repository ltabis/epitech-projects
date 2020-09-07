//
// Created by lucas.tabis on 1/16/19.
//

#ifndef EX00_HPP
#define EX00_HPP

template<typename T>
void swap (T &p1, T &p2)
{
    T tmp = p1;
    p1 = p2;
    p2 = tmp;
}

template<typename T>
T min (T &p1, T &p2)
{
    if (p1 == p2)
        return p2;
    else if (p1 > p2)
        return p2;
    return p1;
}

template<typename T>
T max (T &p1, T &p2)
{
    if (p1 == p2)
        return p2;
    else if (p1 < p2)
        return p2;
    return p1;
}

template<typename T>
T add (T &p1, T &p2)
{
    return p1 + p2;
}

#endif /* !EX00_HPP */
