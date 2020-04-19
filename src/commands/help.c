/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** help.c
*/

#include "help.h"

#include <string.h>

#include "server.h"

void cmd_help(server_t *server, int client_index, char **cmds)
{
    if (!user_get_authorize(server, client_index, cmds)) return;

    if (cmds[1] == NULL) {
        server_send_response(server, client_index, HELP_MAPPING[14].msg);
        server_send_response(server, client_index, RESPONSE_214);
        return;
    }
    for (int i = 0; HELP_MAPPING[i].cmd != NULL; i++) {
        if (strcmp(cmds[1], HELP_MAPPING[i].cmd) == 0) {
            server_send_response(server, client_index, HELP_MAPPING[i].msg);
            server_send_response(server, client_index, RESPONSE_214);
            return;
        }
    }
    server_send_response(server, client_index, HELP_MAPPING[14].msg);
    server_send_response(server, client_index, RESPONSE_214);
}