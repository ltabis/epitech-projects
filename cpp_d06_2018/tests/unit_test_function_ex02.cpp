/*
** EPITECH PROJECT, 2019
** unit_test_function_ex02
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "SickKoala.hpp"
#include "test.hpp"

void redirect_all_std()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(koala, koala_creation)
{
    SickKoala koko("koko");

    cr_assert_eq(koko.takeDrug("Viagra"), false);
    cr_assert_eq(koko.takeDrug("mars"), true);
    cr_assert_eq(koko.takeDrug("Buronzand"), true);
    cr_assert_eq(koko.takeDrug("mdr"), false);
}
