/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** help.h
*/

#ifndef NWP_MY_FTP_2019_HELP_H
#define NWP_MY_FTP_2019_HELP_H

#define HELP_MESSAGE                                                        \
    "USAGE ./my_ftp port path\n\tport\tis the port number on which the "    \
    "server socket listens\n\tpath\tis the path to the home directory for " \
    "the Anonymous user\n"

/*  help.c  */
bool display_help(args_t* arguments);

#endif  // NWP_MY_FTP_2019_HELP_H
