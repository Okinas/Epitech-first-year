##
## EPITECH PROJECT, 2019
## MUL_my_hunter_2019
## File description:
## Makefile
##

MAIN	=	main.c

SRC	=	src/my_pushswap.c 	\
		src/functions_list.c	\
		src/radix_sort.c	\
		src/quicksort.c		\
		src/sort.c

VPATH		=	/usr/local/lib/

OBJ		=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME 		=	push_swap

CFLAGS		=	-Wall -Wextra

CPPFLAGS	= 	-I./include/

LDFLAGS		=	-L./lib/

override LDLIBS 		+= 	-lmy


all:		$(NAME)

$(NAME):	$(LDLIBS) $(OBJ)
		$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

-lmy:
		$(MAKE) -C lib/my

debug:          $(LDLIBS)
		$(CC) -g -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:	LDLIBS += -lcriterion
tests_run:	$(LDLIBS)
		$(CC) -o $@ $(SRC) tests/test_pushswap.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) --coverage
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
