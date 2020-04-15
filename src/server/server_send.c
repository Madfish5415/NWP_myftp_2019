/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** server_send.c
*/

#include "server.h"

void server_send_response(
    server_t* server, int client_index, const char* const response)
{
    buffer_write_string(&server->clients[client_index].write_queue, response);
    if (catch (server->clients[client_index].write_queue.exception)) {
        server->exception = new_exception(RUNTIME_ERROR,
            "server_send_response (server/server_send.c)",
            "Can't write response");
        return;
    }
    FD_SET(server->clients[client_index].socket, &server->master[WRITE_SET]);
}