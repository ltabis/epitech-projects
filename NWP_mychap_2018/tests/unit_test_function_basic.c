/*
** EPITECH PROJECT, 2019
** unit_test_function_basic.c
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include "chap.h"

Test(tests_ftp, create_new_socket_test)
{
    int fd = create_raw_socket();

    cr_assert_neq(fd, 0);
    close(fd);
}

Test(tests_ftp, bind_socket_test)
{
    int fd = create_raw_socket();

    set_socket(fd);
    cr_assert_neq(fd, 0);
    cr_assert_eq(bind_socket(0, 4444), EXIT_FAIL);
    cr_assert_eq(bind_socket(fd, 0), EXIT_FAIL);
    cr_assert_eq(bind_socket(fd, -45), EXIT_FAIL);
    cr_assert_eq(bind_socket(fd, 6666), EXIT_SUCCESS);
    close(fd);
}

Test(tests_ftp, setup_socket_test)
{
    int fd = create_raw_socket();

    cr_assert_eq(set_socket(fd), EXIT_SUCCESS);
    close(fd);
}
