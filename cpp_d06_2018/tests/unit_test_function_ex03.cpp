/*
** EPITECH PROJECT, 2019
** unit_test_function_ex02
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "KoalaNurse.hpp"
#include "test.hpp"

Test(nurse, nurse_creation)
{
    KoalaNurse nurse(13);

    cr_assert_eq(nurse.readReport("test.report"), "drogue");
    cr_assert_eq(nurse.readReport("nope.rep"), "");
    cr_assert_eq(nurse.readReport("nope"), "");
}
