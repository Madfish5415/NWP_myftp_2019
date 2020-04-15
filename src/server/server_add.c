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
    if ((server->clients = realloc(server->clients,
             sizeof(client_t) * (server->clients_nbr + 1))) == NULL) {
        server->exception =
            new_exception(BAD_ALLOC, "server_add_client (server/server_add.c)",
                "Can't realloc 'client_t *'");
        return;
    }
    server->clients[server->clients_nbr] = client;
    buffer_write_string(
        &server->clients[server->clients_nbr].write_queue, RESPONSE_220);
    if (catch (server->clients[server->clients_nbr].write_queue.exception)) {
        server->exception = new_exception(RUNTIME_ERROR,
            "server_add_client (server/server_add.c)", "Can't write string");
        return;
    }
    FD_SET(server->clients[server->clients_nbr].socket,
        &server->master[WRITE_SET]);
    server->clients_nbr++;
}