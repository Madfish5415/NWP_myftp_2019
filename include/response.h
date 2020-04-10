/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** response.h
*/

#ifndef NWP_MY_FTP_2019_RESPONSE_H
#define NWP_MY_FTP_2019_RESPONSE_H

static const char* const RESPONSE_110 = "110 Restart marker reply.\r\n";
static const char* const RESPONSE_120 = "120 Service ready in nnn minutes.\r\n";
static const char* const RESPONSE_125 =
    "125 Data connection already open; transfer starting.\r\n";
static const char* const RESPONSE_150 =
    "150 File status okay; about to open data connection.\r\n";
static const char* const RESPONSE_200 = "200 Command okay.\r\n";
static const char* const RESPONSE_202 =
    "202 Command not implemented, superfluous at this site.\r\n";
static const char* const RESPONSE_211 =
    "211 System status, or system help reply.\r\n";
static const char* const RESPONSE_212 = "212 Directory status.\r\n";
static const char* const RESPONSE_213 = "213 File status.\r\n";
static const char* const RESPONSE_214 =
    "214 Help message.\n"
    "On how to use the server or the meaning of a particular"
    "non-standard command. This reply is useful only to the human user.\r\n";
static const char* const RESPONSE_215 =
    "215 NAME system type.\n"
    "Where NAME is an official system name from the list in the "
    "Assigned Numbers document.\r\n";
static const char* const RESPONSE_220 = "220 Service ready for new user.\r\n";
static const char* const RESPONSE_221 =
    "221 Service closing control connection.\n"
    "Logged out if appropriate.\r\n";
static const char* const RESPONSE_225 =
    "225 Data connection open; no transfer in progress.\r\n";
static const char* const RESPONSE_226 =
    "226 Closing data connection.\n"
    "Requested file action successful (for example, file transfer or file "
    "abort).\r\n";
static const char* const RESPONSE_227 =
    "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\r\n";
static const char* const RESPONSE_230 = "230 User logged in, proceed.\r\n";
static const char* const RESPONSE_250 =
    "250 Requested file action okay, completed.\r\n";
static const char* const RESPONSE_257 = "257 \"PATHNAME\" created.\r\n";
static const char* const RESPONSE_331 =
    "331 User name okay, need password.\r\n";
static const char* const RESPONSE_332 = "332 Need account for login.\r\n";
static const char* const RESPONSE_350 =
    "350 Requested file action pending further information.\r\n";
static const char* const RESPONSE_425 = "425 Can't open data connection.\r\n";
static const char* const RESPONSE_426 =
    "426 Connection closed; transfer aborted.\r\n";
static const char* const RESPONSE_450 =
    "450 Requested file action not taken.\n"
    "File unavailable(e.g., file busy).\r\n";
static const char* const RESPONSE_451 =
    "451 Requested action aborted: local error in processing.\r\n";
static const char* const RESPONSE_452 =
    "452 Requested action not taken.\n"
    "Insufficient storage space in system.\r\n";
static const char* const RESPONSE_500 =
    "500 Syntax error, command unrecognized.\n"
    "This may include errors such as command line too long.\r\n";
static const char* const RESPONSE_501 =
    "501 Syntax error in parameters or arguments.\r\n";
static const char* const RESPONSE_502 = "502 Command not implemented.\r\n";
static const char* const RESPONSE_503 = "503 Bad sequence of commands.\r\n";
static const char* const RESPONSE_504 =
    "504 Command not implemented for that parameter.\r\n";
static const char* const RESPONSE_530 = "530 Not logged in.\r\n";
static const char* const RESPONSE_532 =
    "532 Need account for storing files.\r\n";
static const char* const RESPONSE_550 =
    "550 Requested action not taken.\n"
    "File unavailable (e.g., file not found, no access).\r\n";
static const char* const RESPONSE_551 =
    "551 Requested action aborted: page type unknown.\r\n";
static const char* const RESPONSE_552 =
    "552 Requested file action aborted.\n"
    "Exceeded storage allocation (for current directory or dataset).\r\n";
static const char* const RESPONSE_553 =
    "553 Requested action not taken.\n"
    "File name not allowed.\r\n";

#endif  // NWP_MY_FTP_2019_RESPONSE_H
