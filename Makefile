##
## EPITECH PROJECT, 2022
## jam111
## File description:
## Makefile
##

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	leo

all:
	gcc -o $(NAME) -g $(SRC) -I C:/CSFML/include -L C:/CSFML/lib/gcc -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean re all