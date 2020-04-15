/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** server.h
*/

#ifndef NWP_MY_FTP_2019_SERVER_H
#define NWP_MY_FTP_2019_SERVER_H

#include "arguments.h"
#include "client.h"
#include "exception.h"
#include "response.h"
#include "type.h"
#include "utils.h"

#define MAX_CLIENT_QUEUE 10

#define SET_NUMBER 3
#define READ_SET 0
#define WRITE_SET 1
#define EXCEPT_SET 2

typedef struct server_s {
    uint16_t port;
    char path[PATH_SIZE];
    socket_t socket;
    struct sockaddr_in address;
    size_t address_length;
    fd_set master[SET_NUMBER];
    fd_set worker[SET_NUMBER];
    struct timeval timeout;
    client_t *clients;
    int clients_nbr;
    exception_t exception;
} server_t;

/*  server.c  */
void server(server_t *server);

/*  server_add.c  */
void server_add_client(server_t *server, client_t client);

/*  server_create.c  */
exception_t server_create(server_t **server, args_t *arguments);

/*  server_get.c  */
int server_get_client(server_t *server, int fd);

/*  server_handle.c  */
void server_handle_fd(server_t *server);

/*  server_init.c  */
void server_init(server_t *server);

/*  server_remove.c  */
void server_remove_client(server_t *server, int client_index);

/*  server_send.c  */
void server_send_response(
    server_t* server, int client_index, const char* const response);

#endif  // NWP_MY_FTP_2019_SERVER_H
