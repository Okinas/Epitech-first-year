##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Task01
##

MAIN 			=	src/main.c

SRC				=	src/broken_maze.c	\
					src/generator.c		\
					src/maze_utils.c	\
					src/perfect_gen.c

CFLAGS			=	-Wall -Wextra -O2

CPPFLAGS		=	-I../include/

LDFLAGS 		=	-L../lib/

override LDLIBS	+=	-lmy

OBJ				= 	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME			=	generator

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	clean fclean re