/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** user_create.c
*/

#include <string.h>

#include "user.h"

user_t user_create()
{
    user_t user;

    memset(&user.username, '\0', USERNAME_SIZE);
    memset(&user.password, '\0', PASSWORD_SIZE);
    user.connected = false;
    return user;
}