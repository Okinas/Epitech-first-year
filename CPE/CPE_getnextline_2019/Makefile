##
## EPITECH PROJECT, 2019
## MUL_my_hunter_2019
## File description:
## Makefile
##

MAIN	=	main.c

SRC	=	tests/tests_gnl.c	\
		get_next_line.c

VPATH		=	/usr/local/lib/

CFLAGS		=	-Wall -Wextra

CPPFLAGS	= 	-I./

LDLIBSTEST	=	-lcriterion

tests_run:
		$(CC) -o $@ $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBSTEST) --coverage
		./tests_run
		mv *.gc* tests/
		$(RM) $@

.NOTPARALLEL:
.PHONY:		tests_run
