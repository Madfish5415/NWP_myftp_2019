/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** pwd.c
*/

#include "server.h"

void cmd_pwd(server_t *server, int client_index, char **cmds)
{
    int i = 0;
    int tmp = 0;

    if (!user_get_authorize(server, client_index, cmds)) return;
    buffer_write_string(&server->clients[client_index].write_queue, "257 ");
    for (i = 0; server->clients[client_index].root_path[i] != '\0'; i++);
    tmp = i;
    for (; server->clients[client_index].local_path[i + 1] != '\0'; i++)
        buffer_write_character(&server->clients[client_index].write_queue,
            server->clients[client_index].local_path[i + 1]);
    if (tmp == i)
        buffer_write_character(&server->clients[client_index].write_queue, '/');
    buffer_write_string(&server->clients[client_index].write_queue, "\r\n");
    if (catch (server->clients[client_index].write_queue.exception)) {
        server->exception = new_exception(
            RUNTIME_ERROR, "cmd_pwd (commands/pwd.c)", "Can't write response");
        return;
    }
    FD_SET(server->clients[client_index].socket, &server->master[WRITE_SET]);
}