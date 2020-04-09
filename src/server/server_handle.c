/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** server_handle.c
*/

#include "server.h"

static void handle_read(server_t *server, int fd)
{
    if (!FD_ISSET(fd, &server->worker[READ_SET])) return;
    if (fd == server->socket) {
        client_connect(server);
        if (server->exception.code != NO_ERROR) return;
    } else {

    }
}

void server_handle_read(server_t *server)
{
    for (int fd = 0; fd < FD_SETSIZE; fd++) {
        handle_read(server, fd);
    }
}

static void handle_write(server_t *server, int fd)
{
    if (!FD_ISSET(fd, &server->worker[WRITE_SET])) return;
    if (fd != server->socket) {

    }
}

void server_handle_write(server_t *server)
{
    for (int fd = 0; fd < FD_SETSIZE; fd++) {
        handle_write(server, fd);
    }
}

void server_handle_fd(server_t *server)
{
    server_handle_read(server);
    if (server->exception.code != NO_ERROR)
        return;
    server_handle_write(server);
    if (server->exception.code != NO_ERROR)
        return;
}