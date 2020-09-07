/*
** EPITECH PROJECT, 2018
** unit_test_get_nbr_value.c
** File description:
** unti test for function get_nbr_value in parser.c
*/

#include "test.h"
#include "proto.h"

Test(parser, check_get_nbr_value)
{
	char *command = "1:OK:No errors so far:600.0:625.0:675.0:700.0:750.0:8"\
		"00.0:850.0:900.0:975.0:1050.0:1125.0:1375.0:1500.0:2500.0:275"\
		"0.0:2750.0:2750.0:2750.0:2750.0:2500.0:1500.0:1375.0:1225.0:1"\
		"125.0:1050.0:975.0:900.0:850.0:800.0:750.0:700.0:675.0:No fur"\
		"ther info";
	int value = set_point(command);

	cr_assert_eq(value, 22);
}

Test(parser, check_line_parsing)
{
	value_t values = {0.0, 0.0, 0.0, 0.0, 0.0};
	char *command = "1:OK:No errors so far:100.0:105.0:675.0:700.0:750.0:8"\
		"00.0:850.0:900.0:975.0:1050.0:1125.0:1375.0:1500.0:2500.0:275"\
		"0.0:200.0:200.0:200.0:200.0:2500.0:1500.0:1375.0:1225.0:1"\
		"125.0:1050.0:975.0:900.0:850.0:700.0:750.0:700.0:600.0:No fur"\
		"ther info";

	line_parser(command, &values);
	cr_assert_neq(values.middle, 0);
	cr_assert_neq(values.left, 0);
	cr_assert_neq(values.right, 0);
}
