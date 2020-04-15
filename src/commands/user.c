/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** user.c
*/

#include "server.h"

void cmd_user(server_t *server, int client_index, char **cmds)
{
    if (!user_get_authorize(server, client_index, cmds)) return;

    if (cmds[1] == NULL) {
        server_send_response(server, client_index, RESPONSE_530_USER);
        return;
    }
    user_copy(cmds[1], server->clients[client_index].user.username);
}
