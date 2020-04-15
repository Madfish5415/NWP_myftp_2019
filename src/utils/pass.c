/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** pass.c
*/

#include <stdlib.h>
#include "user.h"

void pass_copy(const char* const src, char *dest)
{
    if (src == NULL || dest == NULL) return;

    for (int i = 0; src[i] != '\0' && i < PASSWORD_SIZE; i++)
        dest[i] = src[i];
}