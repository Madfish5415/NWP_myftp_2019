/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** unknown.c
*/

#include "server.h"

void cmd_unknown(server_t *server, int client_index, char **cmds)
{
    if (!user_get_authorize(server, client_index, cmds)) return;
    server_send_response(server, client_index, RESPONSE_500);
}