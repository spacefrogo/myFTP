/*
** EPITECH PROJECT, 2020
** EPITECH 2020
** File description:
** header file
*/

#ifndef _MY_H_
#define _MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ncurses.h>
#include <dirent.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>

# define BUFFER 1024

typedef struct s_server
{
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int server_len;
    int client_len;
    int server_sockfd;
    int client_sockfd;
    int readsize;
    char *path;
    char ch;
    int code;
    char *username;
    int connected;
    int logged;
    char *present;
    char *c;
    char *gl;
    char *a;
}	t_server;

typedef struct s_function
{
    char *command;
    int (*function)(t_server *, char *args);
}	t_function;

int	check_if_space(char *);
bool 	check_argument(char *);
void	print_help(void);
void	startup_server(t_server *, char *);
void	close_server(t_server *);
int	signal_250(t_server *);
extern	t_function functab[13];
int	func(t_server *server);
int	signal_220(t_server *);
int	signal_250(t_server *);
int	signal_530(t_server *);
int	signal_503(t_server *);
int	signal_250(t_server *);
int	signal_230(t_server *);
int	signal_331(t_server *);
int	signal_214(t_server *);
int	signal_200(t_server *);
int	signal_221(t_server *);
int	signal_257(t_server *);
int	send_error(t_server *);
int	send_error_syntax(t_server *);
void	handle_server(t_server *, char *);
void	start_server(t_server *);
int	cmd_user(t_server *, char *);
int	cmd_pass(t_server *, char *);
int	cmd_noop(t_server *, char *);
int	cmd_help(t_server *, char *);
int	cmd_list(t_server *, char *);
int	cmd_quit(t_server *, char *);
int	cmd_pwd(t_server *, char *);
int	cmd_type(t_server *, char *);
int	cmd_cwd(t_server *, char *);
int	cmd_cdup(t_server *, char *);
int	get_cmd(char *, t_server *);
int	cmd_dele(t_server *, char *);
int	cmd_unknown(t_server *, char *);

#endif // _MY_H_
