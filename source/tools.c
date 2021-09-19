/*
** EPITECH PROJECT, 2020
** EPTECH 2020
** File description:
** tools helping program
*/

#include "my.h"

void    print_help(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport  is the port number");
    printf("on which the server socket listens\n");
    printf("\tpath  is the path to the home ");
    printf("directory for the Anonymous user");
}

bool    check_argument(char *input)
{
    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] < '0' || input[i] > '9')
            return (false);
    }
    return true;
}

int     signal_503(t_server *server)
{
    char *cmd = malloc(30);

    memset(cmd, 0, 30);
    sprintf(cmd, "%d %s%s", 503, "Need Username.", "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    free(cmd);
    return (0);
}

int	cmd_type(t_server *server, char *command)
{
    char *cmd = malloc(30);

    if (server->logged < 2) {
        signal_530(server);
        return (84);
    }
    memset(cmd, 0, 30);
    sprintf(cmd, "%d %s%s", 200, "Binary Mode on.", "\r\n");
    write(server->client_sockfd, cmd, strlen(cmd));
    if (cmd)
        fprintf(stderr, "CMD [%s]\n", cmd);
    free(cmd);
    return (0);
}

int	cmd_dele(t_server *server, char *command)
{
    FILE *file;

    if (!command || command == NULL || !strlen(command)) {
        send_error(server);
        return (84);
    }
    if (!(file = fopen(command, "r")) || server->logged < 2) {
        send_error(server);
        return (84);
    }
    fclose(file);
    remove(command);
    signal_250(server);
    return (0);
}
