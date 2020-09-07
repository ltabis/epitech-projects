/*
** EPITECH PROJECT, 2017
** unit_test_nm.c
** File description:
** unti tests for my_nm
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "test.h"

Test(nm, my_len_special)
{
    cr_assert_eq(len_special(NULL), -1);
    cr_assert_eq(len_special("__data_start"), 9);
}

Test(nm, my_strcmpchar)
{
    cr_assert_eq(strcmpchar("", ""), 1);
    cr_assert_eq(strcmpchar("_data", "fata"), 1);
    cr_assert_eq(strcmpchar("_fata", "data"), 0);
    cr_assert_eq(strcmpchar("data", "data"), 1);
    cr_assert_eq(strcmpchar("data", "datae"), 1);
}

Test(nm, my_unused_name)
{
    char a[] = {1, 1, 1, 1};

    cr_assert_eq(get_unused_name(a, 4), -1);
    a[1] = 0;
    cr_assert_eq(get_unused_name(a, 4), 1);
}

Test(nm, my_check_header)
{
    cr_assert_eq(check_file_header((void *)-1, "pg", "a", 0), 2);
}

Test(nm, my_ex_values)
{
    char a[] = "je suis un test! haha";
    char b[] = "je suis un test! haha";
    char *iterator = display_hex_values(a, b, &a[16]);

    cr_assert_str_eq(iterator, " haha");
}
