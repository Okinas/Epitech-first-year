##
## EPITECH PROJECT, 2019
## MUL_my_hunter_2019
## File description:
## Makefile
##

MAIN	=	main.c

SRC	=	src/my_shell.c		\
		src/error.c		\
		src/fill_env.c		\
		src/env_cmd.c		\
		src/env_function.c	\
		src/command_shell.c	\
		src/exit.c		\
		src/array_str.c		\
		src/my_exec.c		\
		src/cd_cmd.c		\
		src/utils.c

VPATH			=	/usr/local/lib/

OBJ			=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME 			=	mysh

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
		$(CC) -o $@ $(SRC) tests/test_sh.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) --coverage
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
