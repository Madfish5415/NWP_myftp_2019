/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** buffer_create.c
*/

#include "buffer.h"

buffer_t buffer_create()
{
    buffer_t buffer;

    buffer.buffer_length = 0;
    buffer.read_index = 0;
    buffer.write_index = 0;
    buffer.exception.code = NO_ERROR;
    return (buffer);
}