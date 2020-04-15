/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** user_connect.c
*/

#include <string.h>

#include "server.h"

void user_connect(server_t *server, int client_index)
{
    if (strcmp("Anonymous", server->clients[client_index].user.username) == 0) {
        server_send_response(server, client_index, RESPONSE_230);
        server->clients[client_index].user.connected = true;
    } else {
        server_send_response(server, client_index, RESPONSE_530_PASS);
        server->clients[client_index].user = user_create();
    }
}