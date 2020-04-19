/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** help.h
*/

#ifndef NWP_MY_FTP_2019_HELP_H
#define NWP_MY_FTP_2019_HELP_H

static const char *const HELP_MESSAGE =
    "USAGE ./myftp port path\n\tport\tis the port number on which the "
    "server socket listens\n\tpath\tis the path to the home directory for "
    "the Anonymous user\n";

typedef struct help_s {
    char *cmd;
    char *msg;
} help_t;

static const help_t HELP_MAPPING[] = {
    {"QUIT", "214 QUIT <CRLF>                   : Disconnection\r\n"},
    {"USER",
        "214 USER <SP> <username> <CRLF>   : Specify user for "
        "authentication\r\n"},
    {"PASS",
        "214 PASS <SP> <password> <CRLF>   : Specify password for "
        "authentication\r\n"},
    {"NOOP", "214 NOOP <CRLF>                   : Do nothing\r\n"},
    {"CDUP",
        "214 CDUP <CRLF>                   : Change working directory to "
        "parent directory\r\n"},
    {"CWD", "214 CWD  <SP> <pathname> <CRLF>   : Change working directory\r\n"},
    {"DELE",
        "214 DELE <SP> <pathname> <CRLF>   : Delete file on the server\r\n"},
    {"HELP", "214 HELP [<SP> <string>] <CRLF>   : List available commands\r\n"},
    {"LIST",
        "214 STOR <SP> <pathname> <CRLF>   : Upload file from client to "
        "server\r\n"},
    {"PASV", "214 PWD  <CRLF>                   : Print working directory\r\n"},
    {"PORT",
        "214 PORT <SP> <host-port> <CRLF>  : Enable \"active\" mode for data "
        "transfer\r\n"},
    {"PWD", "214 PWD  <CRLF>                   : Print working directory\r\n"},
    {"RETR",
        "214 RETR <SP> <pathname> <CRLF>   : Download file from server to "
        "client\r\n"},
    {"STOR",
        "214 STOR <SP> <pathname> <CRLF>   : Upload file from client to "
        "server\r\n"},
    {NULL,
        "214 QUIT USER PASS NOOP CDUP CWD DELE HELP LIST PASV PORT PWD "
        "RETR\r\n"}};

/*  help.c  */
bool display_help(args_t *arguments);

#endif  // NWP_MY_FTP_2019_HELP_H
