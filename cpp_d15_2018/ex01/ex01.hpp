//
// Created by lucas.tabis on 1/16/19.
//

#ifndef EX01_HPP
#define EX01_HPP

#include <cstring>

template<typename T>
int compare (const T &p1, const T &p2)
{
    if (p1 == p2)
        return 0;
    else if (p1 < p2)
        return -1;
    return 1;
}


#endif /* !EX01_HPP */
