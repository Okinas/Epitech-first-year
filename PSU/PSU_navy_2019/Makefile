##
## EPITECH PROJECT, 2019
## MUL_my_hunter_2019
## File description:
## Makefile
##

MAIN	=	src/main.c

SRC	=	src/attack.c		\
		src/check_file.c	\
		src/check_error.c	\
		src/check.c		\
		src/connection.c	\
		src/free.c		\
		src/map.c		\
		src/navy.c		\
		src/setup.c		\
		src/signal.c

SRCTEST	=	src/check.c		\
		src/check_error.c	\
		src/check_file.c	\
		src/map.c

VPATH			=	/usr/local/lib/

OBJ			=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME 			=	navy

CFLAGS			=	-Wall -Wextra

CPPFLAGS		= 	-I./include/

LDFLAGS			=	-L./lib/

override LDLIBS 	+= 	-lmy


all:		$(NAME)

$(NAME):	$(LDLIBS) $(OBJ)
		$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

-lmy:
		$(MAKE) -C lib/my

debug:          $(LDLIBS)
		$(CC) -g -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:	LDLIBS += -lcriterion
tests_run:	$(LDLIBS)
		$(CC) -o $@ $(SRCTEST) tests/tests_navy.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) --coverage
		./$@
		mv *.gc* tests/
		$(RM) $@

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re: 		fclean all

.NOTPARALLEL:
.PHONY:		debug all clean fclean re tests_run
