/*
** EPITECH PROJECT, 2019
** objdump.hpp
** File description:
** objdump file
*/

#include "objdump.h"

int main(int ac, const char * const *av)
{
    if (check_file_format(ac, av) == FALSE)
        return (FALSE);
    return (TRUE);
}