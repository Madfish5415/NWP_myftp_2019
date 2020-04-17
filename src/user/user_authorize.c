/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** user_authorize.c
*/

#include <string.h>

#include "server.h"

static bool is_connected(server_t *server, int client_index)
{
    return server->clients[client_index].user.connected;
}

bool user_get_authorize(server_t *server, int client_index, char **cmds)
{
    bool is_authorize = false;

    for (int i = 0; AUTHORIZE_LIST[i] != NULL; i++) {
        if (strcmp(AUTHORIZE_LIST[i], cmds[0]) == 0) {
            is_authorize = true;
            break;
        }
    }
    is_authorize = (is_connected(server, client_index)) ? true : is_authorize;
    if (!is_authorize) server_send_response(server, client_index, RESPONSE_530);
    return is_authorize;
}