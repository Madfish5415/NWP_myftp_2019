/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** stor.c
*/

#include "server.h"

void cmd_stor(server_t *server, int client_index, char **cmds)
{
    if (!user_get_authorize(server, client_index, cmds)) return;
}