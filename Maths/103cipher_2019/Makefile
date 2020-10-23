##
## EPITECH PROJECT, 2019
## tmp
## File description:
## Makefile
##

MAIN		=	main.c

SRC		=	src/crypting.c	\
			src/functions.c

VPATH		=	/usr/local/lib/

OBJ		=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME		=	103cipher

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I./include/

LDFLAGS		=	-L./lib/

LDLIBS		=	-lm -lmy

LDLIBSTEST	=	-lm -lmy -lcriterion

all:		$(NAME)

$(NAME):	$(LDLIBS) $(OBJ)
		$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

-lmy:
		$(MAKE) -C lib/my

-l%:
		@echo "Il te manque cette librairie:" $@ && false

debug:		CFLAGS += -g
debug:		$(NAME)

tests_run:	$(LDLIBSTEST)
		$(CC) -o $@ $(SRC) tests/tests_cipher.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBSTEST) --coverage
		./tests_run
		mv *.gc* tests/
		$(RM) $@

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)
		$(RM) lib/libmy.a

re:		fclean all

.NOTPARALLEL:
.PHONY:		debug all clean fclean re
