/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** server_handle_execute.c
*/

#include <server.h>

void server_handle_execute(server_t *server)
{
    if (!server) return;

    for (int i = 0; server->clients && i < server->clients_nbr; i++) {
        if (server->clients[i].read_queue.buffer_length == 0) continue;
        client_execute(server, i);
        if (server->exception.code != NO_ERROR) return;
    }
}