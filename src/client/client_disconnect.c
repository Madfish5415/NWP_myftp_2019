/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** client_disconnect.c
*/

#include <unistd.h>

#include "server.h"

void client_disconnect(server_t *server, int client_index)
{
    close(server->clients[client_index].socket);
    FD_CLR(server->clients[client_index].socket, &server->master[READ_SET]);
    FD_CLR(server->clients[client_index].socket, &server->master[WRITE_SET]);
    FD_CLR(server->clients[client_index].socket, &server->master[EXCEPT_SET]);
    server_remove_client(server, client_index);
}
