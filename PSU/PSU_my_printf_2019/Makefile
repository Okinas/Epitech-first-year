##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/flags_manager.c 		\
		src/functions_flags.c 		\
		src/length_modifier.c 		\
		src/length_modifier_u.c 	\
		src/others_flags.c 			\
		src/get_flags.c 			\
		src/int_len.c 				\
		src/my_printf.c 			\
		lib/my/my_putnbr_u.c 		\
		lib/my/my_putnbr_uspe.c 	\
		lib/my/my_convert.c 		\
		lib/my/my_getnbr.c 			\
		lib/my/my_putchar.c 		\
		lib/my/my_putstr.c 			\
		lib/my/my_strlen.c 			\
		lib/my/my_showstr.c 		\
		lib/my/my_revstr.c 			\
		lib/my/my_convertocta.c 	\
		lib/my/functions/signs.c 	\
		lib/my/functions/spaces.c 	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I./include/

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	@rm -f $(OBJ)

tests_run:
		@rm -f ./coverage/*.gc*
		@gcc -o unit_tests $(SRC) tests/*.c $(CFLAGS) --coverage -lcriterion
		@./unit_tests
		@rm -f unit_tests
		@mkdir -p coverage
		@mv *.gc* coverage/

debug: all
	@gcc -g main.c $(SRC) $(CFLAGS) -L./ -lmy

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
