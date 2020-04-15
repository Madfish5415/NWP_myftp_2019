/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** pass.c
*/

#include "server.h"

void cmd_pass(server_t *server, int client_index, char **cmds)
{
    if (!user_get_authorize(server, client_index, cmds)) return;

    if (server->clients[client_index].user.username[0] == '\0') {
        server_send_response(server, client_index, RESPONSE_503_PASS);
        return;
    }
    if (cmds[1] != NULL)
        pass_copy(cmds[2], server->clients[client_index].user.password);

    user_connect(server, client_index);
}