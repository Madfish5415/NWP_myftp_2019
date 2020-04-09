/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** user.h
*/

#ifndef NWP_MY_FTP_2019_USER_H
#define NWP_MY_FTP_2019_USER_H

#include <stdbool.h>

#define USERNAME_SIZE 32
#define PASSWORD_SIZE 32

typedef struct user_s {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    bool connected;
} user_t;

/*  user_create.c  */
user_t user_create();

#endif  // NWP_MY_FTP_2019_USER_H
