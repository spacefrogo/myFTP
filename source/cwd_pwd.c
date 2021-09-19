/*
** EPITECH PROJECT, 2020
** EPITECH 2020
** File description:
** cwd pwd
*/

#include "my.h"

int	signal_257(t_server *server)
{
    char *cmd = malloc(30);

    memset(cmd, 0, 30);
    sprintf(cmd, "%d %s%s", 257, server->present, "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    free(cmd);
    free(server->present);
    return (0);
}

int	cmd_pwd(t_server *server, char *command)
{
    if (server->logged < 2) {
        signal_530(server);
        return (84);
    }
    if (command != NULL || !(!command)) {
        send_error(server);
        return (84);
    }
    server->path = getcwd(NULL, 0);
    server->present = malloc(sizeof(server->path) + 1024);
    memset(server->present, 0, sizeof(server->path) + 1024);
    sprintf(server->present, "\"%s\" is the current directory", server->path);
    signal_257(server);
    return (0);
}

int	cmd_cwd(t_server *server, char *command)
{
    if (server->logged < 2) {
        signal_530(server);
        return (84);
    }
    if (chdir(realpath(command, 0)) != 0) {
        send_error(server);
        return (84);
    }
    signal_250(server);
    return (0);
}

int	cmd_cdup(t_server *server, char *command)
{
    char *path = "..";
    char *cmd = malloc(30);

    if (server->logged < 2) {
        signal_530(server);
        return (84);
    }
    if (command != NULL || !(!command)) {
        send_error(server);
        return (84);
    }
    chdir(path);
    memset(cmd, 0, 30);
    sprintf(cmd, "%d %s%s", 200, "Command is ok.", "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    free(cmd);
    return (0);
}
