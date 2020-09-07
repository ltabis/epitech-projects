/*
** EPITECH PROJECT, 2019
** unit_test_parameters.hpp
** File description:
** unit_test_parameters class
*/

#include <criterion/criterion.h>
#include "chap.h"

Test(tests_ftp, append_target_test)
{
    parameters_t *parameters = malloc(sizeof(parameters_t));

    cr_assert_neq(parameters, NULL);
    cr_assert_eq(append_target(parameters, "126.13.23.23"), EXIT_SUCCESS);
    cr_assert_str_eq(parameters->target, "126.13.23.23");
    cr_assert_eq(append_target(parameters, "126.13.23.23"), EXIT_FAIL);
}

Test(tests_ftp, append_port_test)
{
    parameters_t *parameters = malloc(sizeof(parameters_t));

    cr_assert_neq(parameters, NULL);
    cr_assert_eq(append_port(parameters, "1231"), EXIT_SUCCESS);
    cr_assert_eq(parameters->port, 1231);
    cr_assert_eq(append_port(parameters, "9843"), EXIT_FAIL);
    parameters->port = 0;
    cr_assert_eq(append_port(parameters, "1231e"), EXIT_FAIL);
    cr_assert_eq(parameters->port, 0);
}

Test(tests_ftp, append_password_test)
{
    parameters_t *parameters = malloc(sizeof(parameters_t));

    cr_assert_neq(parameters, NULL);
    cr_assert_eq(append_password(parameters, "126.13.23.23"), EXIT_SUCCESS);
    cr_assert_str_eq(parameters->password, "126.13.23.23");
    cr_assert_eq(append_password(parameters, "126.13.23.23"), EXIT_FAIL);
}