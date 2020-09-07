/*
** EPITECH PROJECT, 2019
** unit_test_function_basic.c
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include "spoof.h"
#include "socket.h"
#include "utils.h"

Test(tests_ftp, create_new_socket_test)
{
    int fd = create_raw_socket();

    cr_assert_eq(fd, -1);
    close(fd);
}

Test(tests_ftp, bind_socket_test)
{
    int fd = create_raw_socket();

    cr_assert_eq(fd, -1);
    cr_assert_eq(listen_socket(fd), EXIT_FAIL);
    cr_assert_eq(bind_socket(0, 4444), EXIT_FAIL);
    cr_assert_eq(bind_socket(fd, 0), EXIT_FAIL);
    cr_assert_eq(bind_socket(fd, -45), EXIT_FAIL);
    cr_assert_eq(bind_socket(fd, 6666), EXIT_FAIL);
    close(fd);
}
