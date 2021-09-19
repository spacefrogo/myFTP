/*
** EPITECH PROJECT, 2020
** EPITECH 2020
** File description:
** commands
*/

#include "my.h"

t_function	functab[13] =
{
    {"USER", cmd_user},
    {"PASS", cmd_pass},
    {"NOOP", cmd_noop},
    {"HELP", cmd_help},
    {"QUIT", cmd_quit},
    {"PWD" , cmd_pwd},
    {"CWD" , cmd_cwd},
    {"CDUP", cmd_cdup},
    {"TYPE", cmd_type},
    {"DELE", cmd_dele},
    {"LIST", cmd_list},
    {"NOTHING" , NULL}
};

int	cmd_list(t_server *server, char *command)
{
    char *cmd = malloc(30);

    memset(cmd, 0, 30);
    sprintf(cmd, "%d %s%s", 150, "Data transfert ready.", "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    free(cmd);
    return (0);
}

int     signal_331(t_server *server)
{
    char *cmd = malloc(30);

    memset(cmd, 0, 30);
    sprintf(cmd, "%d %s%s", 331, "Need password.", "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    free(cmd);
    return (0);
}

int     signal_250(t_server *server)
{
    char *cmd = malloc(30);

    memset(cmd, 0, 30);
    sprintf(cmd, "%d %s%s", 250, "Successfully executed!", "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    free(cmd);
    return (0);
}
