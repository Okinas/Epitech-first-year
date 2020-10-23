##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MAIN =	../main.c 					\

SRC	=	src/bsq.c					\
		../src/function.c 			\
		../src/check_nbrlines.c 	\
		src/bonus_color.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I../include/

LDFLAGS	=	-L../lib -lmy

NAME	=	bonus

all:	$(NAME)

$(NAME):	$(OBJ)
	make -s -C ../lib/my/
	gcc -o $(NAME) $(OBJ) $(MAIN) $(CFLAGS) ${LDFLAGS}
	@rm -f $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
