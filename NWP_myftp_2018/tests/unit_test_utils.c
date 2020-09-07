/*
** EPITECH PROJECT, 2019
** unit_test_function_basic.c
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(tests_ftp, puterr_tests)
{
    cr_assert_eq(puterr("error"), EXIT_FAIL);
}

Test(tests_ftp, check_arguments_tests)
{
    const char * const av[2] = {"./myftp", "-help"};
    const char * const avv[2] = {"./myftp", "-helpe"};
    const char * const avvv[3] = {"./myftp", "4444", "/"};

    cr_assert_eq(check_arguments(0, NULL), EXIT_FAIL);
    cr_assert_eq(check_arguments(4, NULL), EXIT_FAIL);
    cr_assert_eq(check_arguments(2, av), USAGE);
    cr_assert_eq(check_arguments(2, avv), EXIT_FAIL);
    cr_assert_eq(check_arguments(3, avvv), EXIT_SUCCESS);
}

Test(tests_ftp, print_usage_tests)
{
    cr_assert_eq(print_usage(), USAGE);
}

Test(tests_ftp, is_string_number_tests)
{
    cr_assert_eq(is_string_number("444"), EXIT_SUCCESS);
    cr_assert_eq(is_string_number("444.43"), EXIT_FAIL);
    cr_assert_eq(is_string_number("766e"), EXIT_FAIL);
    cr_assert_eq(is_string_number("abcd"), EXIT_FAIL);
}

Test(tests_ftp, cut_command)
{
    char *command1 = strdup("command");
    char *command2 = strdup("command\r\n");

    cut_command(&command1, 0);
    cut_command(&command2, 0);
    cr_assert_str_eq(command1, "command");
    cr_assert_str_eq(command2, "command");
    free(command1);
    free(command2);
}
