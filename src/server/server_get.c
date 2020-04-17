/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** server_get.c
*/

#include "server.h"

int server_get_client(server_t *server, int fd)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].socket == fd) return i;
    return -1;
}