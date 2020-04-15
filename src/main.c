/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** main.c
*/

#include "server.h"
#include "arguments.h"
#include "help.h"

int main(int argc, char **argv)
{
    server_t *server1;
    args_t *arguments;

    if (catch(parser(argc, argv, &arguments)))
        return (FAILURE);
    if (arguments->flags[HELP_FLAG] == true)
        return (SUCCESS);
    server_create(&server1, arguments);
    if (catch(server1->exception))
        return (FAILURE);
    server_init(server1);
    if (catch(server1->exception))
        return (FAILURE);
    server(server1);
    if (catch(server1->exception))
        return (FAILURE);
    return (SUCCESS);
}