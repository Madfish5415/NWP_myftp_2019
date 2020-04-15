/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** cmd.h
*/

#ifndef NWP_MY_FTP_2019_CMD_H
#define NWP_MY_FTP_2019_CMD_H

#include "server.h"

typedef struct cmd_s {
    char *cmd;
    void (*callback)(server_t *, int, char **);
} cmd_t;

/*  cdup.c  */
void cmd_cdup(server_t *server, int client_index, char **cmds);

/*  cwd.c  */
void cmd_cwd(server_t *server, int client_index, char **cmds);

/*  dele.c  */
void cmd_dele(server_t *server, int client_index, char **cmds);

/*  help.c  */
void cmd_help(server_t *server, int client_index, char **cmds);

/*  list.c  */
void cmd_list(server_t *server, int client_index, char **cmds);

/*  noop.c  */
void cmd_noop(server_t *server, int client_index, char **cmds);

/*  pass.c  */
void cmd_pass(server_t *server, int client_index, char **cmds);

/*  pasv.c  */
void cmd_pasv(server_t *server, int client_index, char **cmds);

/*  port.c  */
void cmd_port(server_t *server, int client_index, char **cmds);

/*  pwd.c  */
void cmd_pwd(server_t *server, int client_index, char **cmds);

/*  quit.c  */
void cmd_quit(server_t *server, int client_index, char **cmds);

/*  retr.c  */
void cmd_retr(server_t *server, int client_index, char **cmds);

/*  stor.c  */
void cmd_stor(server_t *server, int client_index, char **cmds);

/*  unknown.c  */
void cmd_unknown(server_t *server, int client_index, char **cmds);

/*  user.c  */
void cmd_user(server_t *server, int client_index, char **cmds);

#endif  // NWP_MY_FTP_2019_CMD_H
