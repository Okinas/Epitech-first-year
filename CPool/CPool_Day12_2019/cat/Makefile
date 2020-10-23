##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	./main.c		\
		./cat.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I../include

LDFLAGS =	-L../lib/my -lmy

NAME	=	cat

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) ${LDFLAGS}
	rm -f $(OBJ)

tests_run:
	gcc -o unit_tests cat.c ../tests/test_cat.c ${CFLAGS} ${LDFLAGS} --coverage -lcriterion
	./unit_tests

clean:
	rm -f $(OBJ)
	rm -f unit_tests

fclean: clean
	rm -f $(NAME)

re:	fclean all clean

.PHONY : all clean fclean re tests_run
