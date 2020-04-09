/*
** EPITECH PROJECT, 2020
** NWP_my_ftp_2019
** File description:
** path.c
*/

#include <sys/stat.h>

#include "arguments.h"

static int count_args(int argc, char **argv)
{
    int count = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') count++;
    }
    return count;
}

static char *find_path(int argc, char **argv)
{
    for (int i = argc - 1; i > 1; i--)
        if (argv[i][0] != '-') return (argv[i]);
    return (NULL);
}

static bool is_valid(const char *path)
{
    struct stat path_stat;

    stat(path, &path_stat);
    return (!S_ISREG(path_stat.st_mode));
}

exception_t fill_path(int argc, char **argv, args_t *arguments)
{
    char *path;
    exception_t exception = {NO_ERROR};

    if (count_args(argc, argv) != 2)
        return (new_exception(
            INVALID_ARGUMENT, "fill_path (arguments/path.c)", "Invalid argument number"));
    if ((path = find_path(argc, argv)) == NULL)
        return (new_exception(
            INVALID_ARGUMENT, "fill_path (arguments/path.c)", "Unable to find path"));
    if (!is_valid(path))
        return (new_exception(INVALID_ARGUMENT, "fill_path (arguments/path.c)",
            "Path doesn't exist or isn't a directory"));
    arguments->path = path;
    return (exception);
}