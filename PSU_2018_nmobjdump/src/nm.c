/*
** EPITECH PROJECT, 2019
** nm.hpp
** File description:
** nm file
*/

#include "nm.h"

int main(int ac, const char * const *av)
{
    if (check_file_format(ac, av) == FALSE)
        return (FALSE);
    return (TRUE);
}
