/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function
*/

#include "menger.h"

int my_isnum(const char *str)
{
    for (unsigned int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (-1);
    return (0);
}

int my_getnbr(const char *str)
{
    unsigned int i = str && str[0] == '-' ? 1 : 0;
    unsigned int nbr = 0;

    if (!str)
        return (0);
    for (; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            nbr = nbr * 10 + (str[i] - 48);
        else
            return (nbr *= str[0] == '-' ? -1 : 1);
    }
    nbr *= str[0] == '-' ? -1 : 1;
    return (nbr);
}

unsigned int calculate_power(unsigned int number, unsigned int pow)
{
    int backup = number;

    for (unsigned int i = 0; i < pow - 1; i++, number *= backup);
    return (number);
}

int check_power(unsigned int size, unsigned int levels)
{
    if (size >= calculate_power(levels, 3) && size % 3 == 0)
        return (0);
    return (-1);
}

int main(int ac, char **av)
{
    if (ac != 3 || my_isnum(av[1]) == -1 || my_isnum(av[2]) == -1 ||
        check_power(my_getnbr(av[1]), my_getnbr(av[2])) == -1)
        return (84);
    reiterate_squares(my_getnbr(av[1]) / 3, my_getnbr(av[2]),
                    my_getnbr(av[1]) / 3, my_getnbr(av[1]) / 3);
    return (0);
}
