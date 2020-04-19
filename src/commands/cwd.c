/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** CWD.c
*/

#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "server.h"

static bool is_valid(const char *path)
{
    struct stat path_stat;

    stat(path, &path_stat);
    return (S_ISDIR(path_stat.st_mode));
}

static bool path_change(server_t *server, int client_index, char *path)
{
    int i = 0;

    for (i = 0; i < PATH_SIZE && path[i] != '\0' &&
         server->clients[client_index].root_path[i] != '\0'; i++) {
        if (path[i] != server->clients[client_index].root_path[i]) return false;
    }
    if (i == PATH_SIZE || server->clients[client_index].root_path[i] != '\0')
        return false;
    path_copy(path, server->clients[client_index].local_path);
    return true;
}

static char *get_path(const char *src)
{
    bool need_fix = false;
    char dest[PATH_SIZE];

    if (src == NULL) return NULL;
    if (src[0] != '.' && src[0] != '/') need_fix = true;
    if (need_fix) {
        dest[0] = '.';
        dest[1] = '/';
    }
    for (int i = 0; src[i] != '\0'; i++)
        dest[i + ((need_fix) ? 2 : 0)] = src[i];
    dest[strlen(src) + ((need_fix) ? 2 : 0)] = '\0';
    return realpath(dest, NULL);
}

void cmd_cwd(server_t *server, int client_index, char **cmds)
{
    char *path = NULL;

    if (!user_get_authorize(server, client_index, cmds)) return;

    chdir(server->clients[client_index].local_path);
    path = get_path(cmds[1]);
    if (path == NULL || !is_valid(path)) {
        server_send_response(server, client_index, RESPONSE_550);
        return;
    }
    if (!path_change(server, client_index, path)) {
        server_send_response(server, client_index, RESPONSE_550);
        return;
    } else {
        server_send_response(server, client_index, RESPONSE_250);
        return;
    }
}