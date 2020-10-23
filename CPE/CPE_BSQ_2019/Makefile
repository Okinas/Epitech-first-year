##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MAIN =	main.c 					\

SRC	=	src/bsq.c				\
		src/function.c 			\
		src/check_nbrlines.c 	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I./include/

LDFLAGS	=	-L./lib -lmy

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	make -s -C ./lib/my/
	gcc -o $(NAME) $(OBJ) $(MAIN) $(CFLAGS) ${LDFLAGS}
	@rm -f $(OBJ)

tests_run:
	@rm -f ./coverage/*.gc*
	@gcc -o unit_tests $(SRC) tests/*.c --coverage -lcriterion $(CFLAGS) ${LDFLAGS}
	@./unit_tests
	@rm -f unit_tests
	@mkdir -p coverage
	@mv *.gc* coverage/

debug:
	make -s -C ./lib/my/
	gcc -g -o $(NAME) $(SRC) $(MAIN) $(CFLAGS) ${LDFLAGS}

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
