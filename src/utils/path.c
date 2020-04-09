/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** path.c
*/

#include <stdlib.h>
#include "type.h"

void path_copy(const char* const src, char *dest)
{
    if (src == NULL || dest == NULL) return;

    for (int i = 0; src[i] != '\0' && i < PATH_SIZE; i++)
        dest[i] = src[i];
}