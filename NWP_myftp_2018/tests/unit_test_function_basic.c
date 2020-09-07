/*
** EPITECH PROJECT, 2019
** unit_test_function_basic.c
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "ftp.h"

Test(tests_ftp, create_new_socket_test)
{
    int fd = create_new_socket();

    cr_assert_neq(fd, 0);
    close(fd);
}

Test(tests_ftp, listen_socket_test)
{
    int fd = create_new_socket();

    cr_assert_neq(fd, 0);
    cr_assert_eq(listen_socket(0), EXIT_FAIL);
    cr_assert_eq(listen_socket(fd), EXIT_SUCCESS);
    close(fd);
}

Test(tests_ftp, bind_socket_test)
{
    int fd = create_new_socket();

    cr_assert_neq(fd, 0);
    cr_assert_eq(bind_socket(0, 4444), EXIT_FAIL);
    cr_assert_eq(bind_socket(fd, 4444), EXIT_SUCCESS);
    cr_assert_eq(bind_socket(fd, -45), EXIT_FAIL);
    cr_assert_eq(bind_socket(fd, 0), EXIT_FAIL);
    close(fd);
}

Test(tests_ftp, accept_socket_test)
{
    int fd = create_new_socket();

    cr_assert_neq(fd, 0);
    cr_assert_neq(accept_socket(fd), 0);
    close(fd);
}
