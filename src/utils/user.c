/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** user.c
*/

#include <stdlib.h>
#include "user.h"

void user_copy(const char* const src, char *dest)
{
    if (src == NULL || dest == NULL) return;

    for (int i = 0; src[i] != '\0' && i < USERNAME_SIZE; i++)
        dest[i] = src[i];
}