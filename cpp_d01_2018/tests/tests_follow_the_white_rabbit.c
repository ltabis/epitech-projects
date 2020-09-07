/*
** EPITECH PROJECT, 2019
** test.c
** File description:
** test file
*/

#include <criterion/criterion.h>

Test(white_rabbit, test_1)
{
    cr_assert_neq(follow_the_white_rabbit(), 0);
}
