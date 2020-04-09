/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** redirect.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <ctype.h>

void std_redirect_all(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}