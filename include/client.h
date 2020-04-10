/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** client.h
*/

#ifndef NWP_MY_FTP_2019_CLIENT_H
#define NWP_MY_FTP_2019_CLIENT_H

#include <netinet/in.h>

#include "user.h"
#include "type.h"
#include "buffer.h"

typedef enum {
    NONE = 0,
    PASSIVE,
    ACTIVE
} data_mode_t;

typedef struct client_s {
    user_t user;
    socket_t socket;
    socket_t data_socket;
    struct sockaddr_in address;
    size_t address_length;
    data_mode_t data_mode;
    buffer_t read_queue;
    buffer_t write_queue;
    char root_path[PATH_SIZE];
    char local_path[PATH_SIZE];
} client_t;

typedef struct server_s server_t; // Forward declare server_t

/*  client_connect.c  */
void client_connect(server_t *server);

/*  client_disconnect.c  */
void client_disconnect(server_t *server, int client_index);

/*  client_execute.c  */
void client_execute(server_t *server, int client_index);

/*  client_read.c  */
void client_read(server_t *server, int client_index);

/*  client_write.c  */
void client_write(server_t *server, int client_index);

#endif  // NWP_MY_FTP_2019_CLIENT_H
