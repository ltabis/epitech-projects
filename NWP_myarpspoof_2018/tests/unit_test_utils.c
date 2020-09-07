/*
** EPITECH PROJECT, 2019
** unit_test_function_basic.c
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "spoof.h"

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
