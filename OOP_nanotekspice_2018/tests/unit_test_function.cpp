/*
** EPITECH PROJECT, 2019
** unit_test_function_ex02
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Errors.hpp"
#include "Parser.hpp"
#include "Shell.hpp"

void redirect_all_std()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(nts, globalTestOK)
{
    Parser p("true.nts");
    crc::Circuit c;
    Shell shell;
    char *av[2];

    av[0] = strdup("./nanotekspice");
    av[1] = strdup("true.nts");
    cr_assert_eq((c = p.parseFile(2, av)).isReady(), true);
}

Test(nts, globalTestKO)
{
    Parser p("no.nts");
    crc::Circuit c;
    Shell shell;
    char *av[2];

    av[0] = strdup("./nanotekspice");
    av[1] = strdup("no.nts");
    cr_assert_eq((c = p.parseFile(2, av)).isReady(), false);
}

Test(nts, globalTestKO2)
{
    Parser p("no.nts2");
    crc::Circuit c;
    Shell shell;
    char *av[2];

    av[0] = strdup("./nanotekspice");
    av[1] = strdup("no.nts2");
    cr_assert_eq((c = p.parseFile(2, av)).isReady(), false);
}

Test(nts, globalTestKO3)
{
    Parser p("inputno.nts");
    crc::Circuit c;
    Shell shell;
    char *av[2];

    av[0] = strdup("./nanotekspice");
    av[1] = strdup("inputno.nts");
    cr_assert_eq((c = p.parseFile(2, av)).isReady(), true);
}


Test(nts, globalTestOK2)
{
    Parser p("./inputno.nts");
    crc::Circuit c;
    Shell shell;
    char *av[4];

    av[0] = strdup("./nanotekspice");
    av[1] = strdup("inputno.nts");
    av[2] = strdup("a=0");
    av[3] = strdup("b=0");
    cr_assert_eq((c = p.parseFile(4, av)).isReady(), true);
}
