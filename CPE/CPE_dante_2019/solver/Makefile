##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Task01
##

MAIN 			=	src/main.c

SRC				=	src/check_move.c			\
					src/fill_struct.c			\
					src/solver.c				\
					src/utils.c

CFLAGS			=	-Wall -Wextra -O2

CPPFLAGS		=	-I../include/

LDFLAGS 		=	-L../lib/

override LDLIBS	+=	-lmy

OBJ				= 	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME			=	solver

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	clean fclean re