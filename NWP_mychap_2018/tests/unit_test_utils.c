/*
** EPITECH PROJECT, 2019
** unit_test_function_basic.c
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "chap.h"

Test(tests_ftp, puterr_tests)
{
    cr_assert_eq(puterr("error"), EXIT_FAIL);
}

Test(tests_ftp, is_string_number_tests)
{
    cr_assert_eq(is_string_number("444"), EXIT_SUCCESS);
    cr_assert_eq(is_string_number("444.43"), EXIT_FAIL);
    cr_assert_eq(is_string_number("766e"), EXIT_FAIL);
    cr_assert_eq(is_string_number("abcd"), EXIT_FAIL);
}

Test(tests_ftp, cleanup_parameter_test)
{
    parameters_t *parameters = NULL;

    cleanup_parameter(parameters);
    cr_assert_eq(parameters, NULL);
    parameters = malloc(sizeof(parameters_t));
    cr_assert_neq(parameters, NULL);
    parameters->password = strdup("PASS");
    parameters->target = strdup("TARG");
    parameters->port = 12;
    cr_assert_neq(parameters, NULL);
    cleanup_parameter(parameters);
    cr_assert_neq(parameters, 0);
}