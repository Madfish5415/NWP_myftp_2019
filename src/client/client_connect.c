/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** client_create.c
*/

#include <string.h>

#include "buffer.h"
#include "client.h"
#include "server.h"

static void client_accept(server_t *server, client_t *client)
{
    if ((client->socket =
                accept(server->socket, (struct sockaddr *)&client->address,
                    (socklen_t *)&client->address_length)) < 0) {
        server->exception = new_exception(RUNTIME_ERROR,
            "client_connect (client/client_connect.c)",
            "Can't accept connection");
    }
}

static void client_init(server_t *server, client_t *client)
{
    client->user = user_create();
    client->data_socket = 0;
    client->data_mode = NONE;
    client->read_queue = buffer_create();
    client->write_queue = buffer_create();
    path_copy(server->path, client->root_path);
    path_copy(server->path, client->local_path);
}

void client_connect(server_t *server)
{
    client_t client;

    client_init(server, &client);
    if (server->exception.code != NO_ERROR) return;
    client_accept(server, &client);
    if (server->exception.code != NO_ERROR) return;
    server_add_client(server, client);
    if (server->exception.code != NO_ERROR) return;
    FD_SET(client.socket, &server->master[READ_SET]);
}