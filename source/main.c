/*
** EPITECH PROJECT, 2020
** EPITECH 2020
** File description:
** main c file
*/

#include "my.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	handle_server(t_server *server, char *av)
{
    server->server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server->server_address.sin_family = AF_INET;
    server->server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server->server_address.sin_port = htons(atoi(av));
    server->server_len = sizeof(server->server_address);
    bind(server->server_sockfd,
         (struct sockaddr *)&server->server_address, server->server_len);
    listen(server->server_sockfd, 10);
}

void	start_server(t_server *server)
{
    char argument[BUFFER];

    while (1) {
        server->client_len = sizeof(server->client_address);
        server->client_sockfd = accept(server->server_sockfd,
                                       (struct sockaddr *)
                                       &server->client_address,
                                       &server->client_len);
        if (fork() == 0) {
            startup_server(server, argument);
            for (;server->readsize =
                     read(server->client_sockfd, argument, BUFFER) > 0;) {
                get_cmd(argument, server);
                bzero(argument, BUFFER);
            }
            close_server(server);
        } else {
            close_server(server);
        }
    }
}

void	startup_server(t_server *server, char *argument)
{
    signal_220(server);
    bzero(argument, BUFFER);
}

void	close_server(t_server *server)
{
    close(server->client_sockfd);
}

int	main(int ac, char **av)
{
    t_server *server = malloc(sizeof(t_server));

    if (ac != 3 || !av[1] || !av[2]) {
        print_help();
        return (84);
    }
    if (check_argument(av[1]) == false) {
        print_help();
        return (84);
    }
    if (!realpath(av[2], server->path)) {
        print_help();
        return (84);
    }
    handle_server(server, av[1]);
    start_server(server);
    return (0);
}
