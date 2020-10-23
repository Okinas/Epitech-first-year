##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	./op.c		\
		./do_op.c 	\
		./my_putchar.c	\
		./my_getnbr.c	\
		./my_putstr.c	\
		./my_put_nbr.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I../include

NAME	=	do-op

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) ${CFLAGS}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur

.PHONY : all clean fclean re
