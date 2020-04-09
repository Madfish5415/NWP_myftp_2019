/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** server_add.c
*/

#include "client.h"
#include "server.h"

void server_add_client(server_t *server, client_t client)
{
    if ((server->clients = realloc(server->clients, sizeof(client_t) * (server->clients_nbr + 1))) ==
        NULL) {
        server->exception =
            new_exception(BAD_ALLOC, "server_add_client (server/server_add.c)",
                "Can't realloc 'client_t *'");
        return;
    }
    server->clients[server->clients_nbr] = client;
    server->clients_nbr++;
}