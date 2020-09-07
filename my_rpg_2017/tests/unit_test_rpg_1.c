/*
** EPITECH PROJECT, 2018
** unit_test_rpg_1.c
** File description:
** testing rpg
*/

#include "test.h"
#include "combat.h"

Test(rpg_testing, testing_nbr_to_str_convertion)
{
	char *nbr = convert_nbr_to_str(42);

	cr_assert_str_eq(nbr, "42");
}
