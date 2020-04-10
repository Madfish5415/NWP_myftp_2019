/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** test1.c
*/

#include <criterion/criterion.h>
#include <stdio.h>

#include "utils.h"

Test(split, split_01)
{
    char str[] = "It's a test for split function";
    char **result = split(str, " ");

    if (result == NULL) cr_assert_eq(1, 0);
    if (strcmp(result[0], "It's") == 0 && strcmp(result[1], "a") == 0 &&
        strcmp(result[2], "test") == 0 && strcmp(result[3], "for") == 0 &&
        strcmp(result[4], "split") == 0 && strcmp(result[5], "function") == 0 &&
        result[6] == NULL)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 0);
}

Test(split, split_02)
{
    char str[] = "It's a test for split function";
    char **result = split(str, "_");

    if (strcmp(result[0], "It's a test for split function") == 0 &&
        result[1] == NULL)
        cr_assert_eq(1, 1);
    else {
        cr_assert_eq(1, 0);
    }
}