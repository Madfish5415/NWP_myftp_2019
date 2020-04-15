/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** user.h
*/

#ifndef NWP_MY_FTP_2019_USER_H
#define NWP_MY_FTP_2019_USER_H

#include <stdbool.h>
#include <stddef.h>

#define USERNAME_SIZE 32
#define PASSWORD_SIZE 32

typedef struct user_s {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    bool connected;
} user_t;

static const char* const AUTHORIZE_LIST[] = {
    "USER",
    "PASS",
    "QUIT",
    "HELP",
    NULL
};

typedef struct server_s server_t;

/*  user_authorize.c  */
bool user_get_authorize(server_t *server, int client_index, char **cmds);

/*  user_connect.c  */
void user_connect(server_t *server, int client_index);

/*  user_create.c  */
user_t user_create(void);

#endif  // NWP_MY_FTP_2019_USER_H
