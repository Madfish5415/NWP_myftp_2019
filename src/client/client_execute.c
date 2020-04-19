/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** client_execute.c
*/

#include <string.h>

#include "cmd.h"
#include "server.h"

static const cmd_t CMD_MAPPING[] = {{"QUIT", &cmd_quit}, {"USER", &cmd_user},
    {"PASS", &cmd_pass}, {"NOOP", &cmd_noop}, {"CDUP", &cmd_cdup},
    {"CWD", &cmd_cwd}, {"DELE", &cmd_dele}, {"HELP", &cmd_help},
    {"LIST", &cmd_list}, {"PASV", &cmd_pasv}, {"PORT", &cmd_port},
    {"PWD", &cmd_pwd}, {"RETR", &cmd_retr}, {"STOR", &cmd_stor},
    {"UNKNOWN", NULL}};

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
    str = strtok(str, "\n");
    str = strtok(str, "\r");
    cmds = split(str, " ");
    if (cmds) execute(server, client_index, cmds);
}