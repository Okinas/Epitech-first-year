##
## EPITECH PROJECT, 2019
## MUL_my_hunter_2019
## File description:
## Makefile
##

MAIN	=	main.c

SRC	=	src/check_content.c 	\
		src/copy.c 		\
		src/map_info.c		\
		src/game_loop.c		\
		src/game_events.c	\
		src/move.c		\
		src/my_sokoban.c

VPATH		=	/usr/local/lib/

OBJ		=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME 		=	my_sokoban

CFLAGS		=	-Wall -Wextra

CPPFLAGS	= 	-I./include/

LDFLAGS		=	-L./lib/

LDLIBS 		= 	-lncurses -lmy

LDLIBSTEST	=	-lmy -lcriterion

all:		$(NAME)

$(NAME):	$(LDLIBS) $(OBJ)
		$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

-lmy:
		$(MAKE) -C lib/my

-l%:
		@echo "Il te manque cette librairie:" $@ && false

debug:          CFLAGS += -g
debug:		$(NAME)

test_run:       $(LDLIBSTEST)
		$(CC) -o $@ $(SRC) tests/test_sokoban.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBSTEST) --coverage
		./test_run
		$(RM) $@

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)
		$(RM) lib/libmy.a

re: 		fclean all

.NOTPARALLEL:
.PHONY:		debug all clean fclean re test_run
