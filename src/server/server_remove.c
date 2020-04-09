/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** server_remove.c
*/

#include "server.h"

void server_remove_client(server_t *server, int client_index)
{
    client_t tmp;

    if (client_index >= server->clients_nbr) {
        server->exception = new_exception(OUT_OF_RANGE,
            "server_remove_client (server/server_remove.c)",
            "Index is out of range");
        return;
    }
    tmp = server->clients[client_index];
    server->clients[client_index] = server->clients[server->clients_nbr - 1];
    server->clients[server->clients_nbr - 1] = tmp;
    if ((server->clients = realloc(server->clients, sizeof(client_t) * (server->clients_nbr - 1))) ==
        NULL) {
        server->exception = new_exception(BAD_ALLOC,
            "server_remove_client (server/server_remove.c)",
            "Can't realloc 'client_t *'");
        return;
    }
    server->clients_nbr--;
}