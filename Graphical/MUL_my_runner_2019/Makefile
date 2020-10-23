##
## EPITECH PROJECT, 2019
## MUL_my_hunter_2019
## File description:
## Makefile
##

MAIN	=	main.c

SRC	=	src/elements.c		\
		src/game.c		\
		src/map_setup.c		\
		src/setup_src.c		\
		src/window.c		\
		src/start_game.c

VPATH		=	/usr/local/lib/

OBJ		=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME 		=	my_runner

CFLAGS		=	-Wall -Wextra

CPPFLAGS	= 	-I./include/

LDFLAGS	=	-L./lib/

LDLIBS = 	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lmy

all:		$(NAME)

$(NAME):	$(LDLIBS) $(OBJ)
		$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

-lmy:
		$(MAKE) -C lib/my

-l%:
		@echo "Il te manque cette librairie:" $@ && false

debug:          CFLAGS += -g
debug:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re: 		fclean all

.NOTPARALLEL:
.PHONY:		debug all clean fclean re
