/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** test1.c
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <unistd.h>

#include "buffer.h"

Test(buffer_read, buffer_read_01)
{
    buffer_t buffer;
    char *str = NULL;

    buffer.write_index = 17;
    buffer.read_index = 0;
    buffer.buffer_length = 17;
    buffer.exception.code = NO_ERROR;
    memset(buffer.buffer, '\0', BUFFER_SIZE);
    for (int i = 0; i < 17; i++)
        buffer.buffer[i] = (char) ((char) i + 'a');
    str = buffer_read_string(&buffer);
    if (catch(buffer.exception)) {
        free(str);
        cr_assert_eq(1, 0);
    }
    if (strcmp(str, "abcdefghijklmnopq") == 0) {
        free(str);
        cr_assert_eq(1, 1);
    } else {
        free(str);
        cr_assert_eq(1, 0);
    }
}

Test(buffer_read, buffer_read_02)
{
    buffer_t buffer;
    char *str = NULL;

    buffer.write_index = 13;
    buffer.read_index = 1020;
    buffer.buffer_length = 17;
    buffer.exception.code = NO_ERROR;
    memset(buffer.buffer, '\0', BUFFER_SIZE);
    for (int i = 0 + 1020; i < 17 + 1020 ; i++)
        buffer.buffer[i % BUFFER_SIZE] = (char) ((char) i - 1020 + 'a');
    str = buffer_read_string(&buffer);
    if (catch(buffer.exception)) {
        free(str);
        cr_assert_eq(1, 0);
    }

    write(1, str, 17);

    if (strcmp(str, "abcdefghijklmnopq") == 0) {
        free(str);
        cr_assert_eq(1, 1);
    } else {
        free(str);
        cr_assert_eq(1, 0);
    }
}