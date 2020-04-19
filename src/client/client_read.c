/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** client_read.c
*/

#include <unistd.h>

#include "server.h"

void client_read(server_t *server, int client_index)
{
    int read_value = 0;
    char buffer[BUFFER_SIZE];

    if ((read_value = read(server->clients[client_index].socket,
             buffer, BUFFER_SIZE)) < 0) {
        server->exception = new_exception(RUNTIME_ERROR,
            "client_read (client_read.c)", "Can't read on the client fd");
        return;
    }
    if (read_value == 0) {
        client_disconnect(server, client_index);
    } else {
        buffer_write_string(&server->clients[client_index].read_queue, buffer);
        if (catch (server->clients[client_index].read_queue.exception)) {
            server->exception = new_exception(RUNTIME_ERROR,
                "client_read (client_read.c)", "Can't write string");
            return;
        }
    }
}