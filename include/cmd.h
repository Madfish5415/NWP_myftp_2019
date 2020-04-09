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
    void (*callback)(server_t *, client_t *, char *);
} cmd_t;



#endif  // NWP_MY_FTP_2019_CMD_H
