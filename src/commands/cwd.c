/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** CWD.c
*/

#include <sys/stat.h>

#include "server.h"

static bool is_valid(const char *path)
{
    struct stat path_stat;

    stat(path, &path_stat);
    return (!S_ISREG(path_stat.st_mode));
}

void cmd_cwd(server_t *server, int client_index, char **cmds)
{
    if (!user_get_authorize(server, client_index, cmds)) return;

    if (cmds[1] == NULL && !is_valid(cmds[1])) {
        server_send_response(server, client_index, RESPONSE_550);
        return;
    }
}