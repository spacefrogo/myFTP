/*
** EPITECH PROJECT, 2020
** EPITECH 2020
** File description:
** User and Password
*/

#include "my.h"

int     cmd_user(t_server *server, char *args)
{
    char *username = "Anonymous";

    server->logged = 0;
    if (args == NULL || !args) {
        signal_530(server);
        return (84);
    }
    if (strcmp(username, args) != 0) {
        signal_530(server);
        return (84);
    }
    signal_331(server);
    server->logged = 1;
    return (0);
}

int     cmd_pass(t_server *server, char *args)
{
    char *password = "";
    
    if (server->logged == 0) {
        signal_503(server);
        return (84);
    }
    if (args == NULL || !args) {
        signal_530(server);
        return (84);
    }
    if (strcmp(password, args) != 0){
        signal_530(server);
        return (84);
    }
    if (server->logged == 1) {
        signal_230(server);
        server->logged = 2;
    }
    if (server->logged == 2)
        signal_230(server);
    return (0);
}
