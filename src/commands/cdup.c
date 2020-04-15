/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** cdup.c
*/

#include "server.h"

void cmd_cdup(server_t *server, int client_index, char **cmds)
{
    if (!user_get_authorize(server, client_index, cmds)) return;

    path_copy(server->clients[client_index].root_path, server->clients[client_index].local_path);
    server_send_response(server, client_index, RESPONSE_250);
}