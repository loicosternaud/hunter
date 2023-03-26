##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## BSQ
##

SRC =	my_put.c \
	display_destroy.c \
	event.c \
	my_hunter.c \

OBJ	=	$(SRC:.c=.o)

NAME =	my_hunter

all :	$(NAME)

$(NAME)	:	$(OBJ)
	gcc $(SRC) -o $(NAME) -lcsfml-graphics -lcsfml-system -lcsfml-window

clean :
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
