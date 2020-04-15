/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** server_create.c
*/

#include <stdlib.h>
#include <string.h>

#include "server.h"

exception_t server_create(server_t **server, args_t *arguments)
{
    server_t *new_server = malloc(sizeof(server_t));

    if (new_server == NULL)
        return (
            new_exception(BAD_ALLOC, "server_create (server/server_create.c)",
                "Can't allocate memory for 'server_t'"));
    (*server) = new_server;
    if ((new_server->port = arguments->port) == 0)
        return (new_exception(INVALID_ARGUMENT,
            "server_create (server/server_create.c)", "Invalid port detected"));
    path_copy(realpath(arguments->path, NULL), new_server->path);
    new_server->clients_nbr = 0;
    new_server->socket = -1;
    new_server->exception.code = NO_ERROR;
    new_server->address_length = sizeof(new_server->address);
    new_server->timeout.tv_sec = 2;
    new_server->timeout.tv_usec = 0;
    return (new_server->exception);
}