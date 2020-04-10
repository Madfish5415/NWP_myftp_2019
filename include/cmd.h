/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** cmd.h
*/

#ifndef NWP_MY_FTP_2019_CMD_H
#define NWP_MY_FTP_2019_CMD_H

#include "server.h"

typedef struct cmd_s {
    char *cmd;
    void (*callback)(server_t *, int, char **);
} cmd_t;

/*  quit.c  */
void cmd_quit(server_t *server, int client_index, char **cmds);

/*  unknown.c  */
void cmd_unknown(server_t *server, int client_index, char **cmds);

#endif  // NWP_MY_FTP_2019_CMD_H
