/*
** EPITECH PROJECT, 2020
** EPITECH 2020
** File description:
** minor commands
*/

#include "my.h"

int	cmd_help(t_server *server, char *args)
{
    char *cmd = malloc(30);

    if (server->logged == 2) {
        memset(cmd, 0, 30);
        sprintf(cmd, "%d %s%s", 214, "HELP.", "\r\n");
        write(server->client_sockfd, cmd, strlen(cmd));
        if (cmd)
            fprintf(stderr, "CMD [%s]\n", cmd);
        free(cmd);
        return (0);
    }
    free(cmd);
    return (84);
}

int     signal_220(t_server *server)
{
    char *cmd = malloc(30);

    memset(cmd, 0, 33);
    sprintf(cmd, "%d %s%s", 220, "Welcome", "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    free(cmd);
    return (0);
}

int	cmd_quit(t_server *server, char *args)
{
    char *cmd = malloc(50);

    memset(cmd, 0, 50);
    sprintf(cmd, "%d %s%s", 221, "Disconnected.", "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    close(server->client_sockfd);
    free(cmd);
    return (0);
}

int     signal_230(t_server *server)
{
    char *cmd = malloc(20);

    memset(cmd, 0, 22);
    sprintf(cmd, "%d %s%s", 230, "Login done.", "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    free(cmd);
    return (0);
}

int	cmd_noop(t_server *server, char *args)
{
    char *cmd = malloc(30);

    if (server->logged == 2) {
        memset(cmd, 0, 30);
        sprintf(cmd, "%d %s%s", 200, "Command is ok.", "\r\n");
        write(server->client_sockfd, cmd, strlen(cmd));
        if (cmd)
            fprintf(stderr, "CMD [%s]\n", cmd);
        free(cmd);
        return (0);
    }
    free(cmd);
    return (84);
}
