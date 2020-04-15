/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** server.c
*/

#include "server.h"

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "exception.h"

void server(server_t* server)
{
    while (true) {
        server->worker[READ_SET] = server->master[READ_SET];
        server->worker[WRITE_SET] = server->master[WRITE_SET];
        server->worker[EXCEPT_SET] = server->master[EXCEPT_SET];

        if (select(FD_SETSIZE, &server->worker[READ_SET],
                &server->worker[WRITE_SET], &server->worker[EXCEPT_SET],
                &server->timeout) < 0) {
            server->exception =
                new_exception(RUNTIME_ERROR, "server", "Select failed");
            return;
        }
        server_handle_fd(server);
        if (server->exception.code != NO_ERROR) return;
    }
}