##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

SRC		=	total.c			\
			error.c			\
			putlong.c		\
			my_ls_d.c		\
			my_ls_l.c		\
			data.c			\
			documentation.c	\
			my_ls.c			\

NAME	=	my_ls

LIBRARY = 	make -C lib/my

CFLAGS 	= 	-g3 -W -Wall -Wextra

all:		$(NAME)

$(NAME):
			$(LIBRARY)
			gcc -o $(NAME) $(CFLAGS) $(SRC) -L ./lib/my/ -lmy

clean:
			$(LIBRARY) clean

fclean:		clean
			rm -f $(NAME)
			$(LIBRARY) fclean

re:			fclean all