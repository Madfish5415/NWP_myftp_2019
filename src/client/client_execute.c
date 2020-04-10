/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** client_execute.c
*/

#include <string.h>

#include "server.h"
#include "cmd.h"

static const cmd_t CMD_MAPPING[] = {
    {"QUIT", &cmd_quit},
    {"UNKNOWN", NULL}
};

static void execute(server_t *server, int client_index, char **cmds)
{
    int i = 0;

    for (i = 0; CMD_MAPPING[i].callback != NULL; i++) {
        if (strcmp(CMD_MAPPING[i].cmd, cmds[0]) == 0) {
            CMD_MAPPING[i].callback(server, client_index, cmds);
            break;
        }
    }
    if (CMD_MAPPING[i].callback == NULL)
        cmd_unknown(server, client_index, cmds);
}

void client_execute(server_t *server, int client_index)
{
    char *str = buffer_read_string(&server->clients[client_index].read_queue);
    char **cmds = NULL;

    if (catch (server->clients[client_index].write_queue.exception)) {
        server->exception = new_exception(RUNTIME_ERROR,
            "client_execute (client_execute.c)", "Can't read string");
        return;
    }
    str = strtok(str, "\r\n");
    cmds = split(str, " ");
    execute(server, client_index, cmds);
}