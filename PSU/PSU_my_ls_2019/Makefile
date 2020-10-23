##
## EPITECH PROJECT, 2019
## MUL_my_hunter_2019
## File description:
## Makefile
##

MAIN	=	main.c

SRC	=	src/my_ls.c		\
		src/access_right.c 	\
		src/general_function.c 	\
		src/init_struct.c 	\
		src/option_ls_l.c	\
		src/option_ls_r.c	\
		src/option_ls_t.c	\
		src/option_ls.c		\
		src/options.c

VPATH		=	/usr/local/lib/

OBJ		=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME 		=	my_ls

CFLAGS		=	-Wall -Wextra

CPPFLAGS	= 	-I./include/

LDFLAGS		=	-L./lib/

LDLIBS 		= 	-lmy

LDLIBSTEST	=	-lmy -lcriterion

all:		$(NAME)

$(NAME):	$(LDLIBS) $(OBJ)
		$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

-lmy:
		$(MAKE) -C lib/my

debug:          $(LDLIBS)
		$(CC) -g -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:	$(LDLIBSTEST) fclean
		$(CC) -o $@ $(SRC) tests/tests_ls.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBSTEST) --coverage
		./tests_run
		mv *.gc* coverage/
		$(RM) $@

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re: 		fclean all

.NOTPARALLEL:
.PHONY:		debug all clean fclean re tests_run
