/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** utils.h
*/

#ifndef NWP_MY_FTP_2019_UTILS_H
#define NWP_MY_FTP_2019_UTILS_H

/*  pass.c  */
void pass_copy(const char *const src, char *dest);

/*  path.c  */
void path_copy(const char *const src, char *dest);

/*  split.c  */
char **split(char *str, char *delim);

/*  user.c  */
void user_copy(const char *const src, char *dest);

#endif  // NWP_MY_FTP_2019_UTILS_H
