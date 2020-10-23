##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Task01
##

all:
	$(MAKE) -C ./lib/my
	$(MAKE) -C ./generator/
	$(MAKE) -C ./solver/

clean:
		$(MAKE) -C ./generator clean
		$(MAKE) -C ./solver/ clean

fclean:		clean
		$(MAKE) -C ./generator fclean
		$(MAKE) -C ./solver/ fclean

re:		fclean all
