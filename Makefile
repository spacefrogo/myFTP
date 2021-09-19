##
## EPITECH PROJECT, 2020
## EPITECH 2020
## File description:
## makefile myftp
##

CFLAGS		=	-Wall -Werror -I./

SRC		=	$(wildcard source/*.c)

NAME		=	myftp

all: link

link: $(SRC)
		@gcc -o $(NAME) $(SRC) -I ./include -lncurses -ggdb -g -g3 -L.
		@echo -n "[ "
		@echo -n "\e[1;32mOK\e[0m"
		@echo -n " ] "
		@echo 	 "\e[1;31mCompiling finished!\e[0m"

debug: 	$(SRC)
		gcc -c -g $(SRC) $(CFLAGS)

clean:
		@rm -f $(NAME)
		@rm -f *~
		@rm -f source/*~
		@rm -f include/*~
		@echo -n "[ "
		@echo -n "\e[1;32mOK\e[0m"
		@echo -n " ] "
		@echo	"\e[1;31mREMOVED THE BINARY FILE AND USELESS FILES!\e[0m"


fclean: 	clean
		@echo -n "[ "
		@echo -n "\e[1;32mOK\e[0m"
		@echo -n " ] "
		@echo	"\e[1;31mForce clean is completed!\e[0m"


re: 		fclean all
		@echo -n "[ "
		@echo -n "\e[1;32mOK\e[0m"
		@echo -n " ] "
		@echo	"\e[1;31mForce make is completed!\e[0m"


.PHONY: 	all obj link clean fclean re
