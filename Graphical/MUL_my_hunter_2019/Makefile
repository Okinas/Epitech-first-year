##
## EPITECH PROJECT, 2019
## MUL_my_hunter_2019
## File description:
## Makefile
##

MAIN	=	main.c

SRC	=	src/analyze_event.c 		\
		src/struct_init/my_game.c 	\
		src/struct_init/apply_sprites.c \
		src/fox/fox_animation.c 	\
		src/fox/dead_fox.c 		\
		src/menu/menu.c 		\
		src/menu/pause.c 		\
		src/menu/end_game.c 		\
		src/text/text.c 		\
		src/create_window.c 		\
		src/game_loop.c 		\
		src/game_event.c 		\
		src/cursor.c 			\
		src/draw.c 			\
		src/free_ressources.c 		\
		src/begin.c 			\
		src/sound.c 			\
		src/read_score.c

VPATH		=	/usr/local/lib/

OBJ		=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME 		=	my_hunter

CFLAGS		=	-Wall -Wextra

CPPFLAGS	= 	-I./include/

LDFLAGS	=	-L./lib/

LDLIBS = 	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lmy

all:		$(NAME)

$(NAME):	$(LDLIBS) $(OBJ)
		$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

-lmy:
		$(MAKE) -C lib/my

-l%:
		@echo "Il te manque cette librairie:" $@ && false

debug:          CFLAGS += -g
debug:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re: 		fclean all

.NOTPARALLEL:
.PHONY:		debug all clean fclean re
