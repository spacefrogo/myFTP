/*
** EPITECH PROJECT, 2020
** EPITECH 2020
** File description:
** aaaa
*/

#include "my.h"

int     get_cmd(char *msg, t_server *server)
{
    server->gl = strtok(msg, "\r\n");
    if (strlen(msg) > 300) {
        send_error_syntax(server);
        return (84);
    }
    while (server->gl) {
        server->c = strsep(&server->gl, " ");
        server->a = server->gl;
        for (int i = 0; functab[i].command != NULL; i++) {
            if (strcmp(functab[i].command, "NOTHING") == 0) {
                send_error_syntax(server);
                return (84);
            }
            if (!strcmp(functab[i].command, server->c))
                return (functab[i].function(server, server->a));
        }
        server->gl = strtok(NULL, "\r\n");
    }
    return (0);
}

int	signal_530(t_server *server)
{
    char *cmd = malloc(30);

    memset(cmd, 0, 30);
    sprintf(cmd, "%d %s%s", 530, "Bad login", "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    free(cmd);
    return (0);
}

int	send_error(t_server *server)
{
    char *cmd = malloc(30);

    memset(cmd, 0, 33);
    sprintf(cmd, "%d %s%s", 550, "Wrong.", "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    free(cmd);
    return (0);
}

int	send_error_syntax(t_server *server)
{
    char *cmd = malloc(30);

    memset(cmd, 0, 33);
    sprintf(cmd, "%d %s%s", 500, "Error Syntax.", "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    free(cmd);
    return (0);
}
