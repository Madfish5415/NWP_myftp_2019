/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** client_write.c
*/

#include <string.h>
#include <unistd.h>

#include "server.h"

void client_write(server_t *server, int client_index)
{
    char *str = buffer_read_string(&server->clients[client_index].write_queue);

    if (catch (server->clients[client_index].write_queue.exception)) {
        server->exception = new_exception(RUNTIME_ERROR,
            "client_write (client_write.c)", "Can't read string");
        return;
    }
    write(server->clients[client_index].socket, str, strlen(str));
    FD_CLR(server->clients[client_index].socket, &server->master[WRITE_SET]);
    if (strcmp(str, RESPONSE_221) == 0)
        client_disconnect(server, client_index);
    free(str);
}