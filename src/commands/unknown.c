/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** unknown.c
*/

#include "server.h"

void cmd_unknown(server_t *server, int client_index, char **cmds)
{
    (void)cmds;
    buffer_write_string(
        &server->clients[client_index].write_queue, RESPONSE_500);
    if (catch (server->clients[client_index].write_queue.exception)) {
        server->exception = new_exception(
            RUNTIME_ERROR, "cmd_quit (commands/quit.c)", "Can't write string");
        return;
    }
    FD_SET(server->clients[client_index].socket, &server->master[WRITE_SET]);
}