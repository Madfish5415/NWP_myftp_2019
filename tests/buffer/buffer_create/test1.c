/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** test_buffer_create_1.c
*/

#include <criterion/criterion.h>

#include "buffer.h"

Test(buffer_create, buffer_create_01)
{
    buffer_t buffer = buffer_create();

    if (buffer.buffer_length == 0 && buffer.read_index == 0 &&
        buffer.write_index == 0 && buffer.exception.code == NO_ERROR)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 0);
}