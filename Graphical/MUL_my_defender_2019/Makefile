##
## EPITECH PROJECT, 2019
## MUL_my_hunter_2019
## File description:
## Makefile
##

MAIN	=	src/main.c

SRC	=	src/gameloop.c							\
		src/window.c							\
		src/save_data.c							\
		src/free/free_all.c						\
		src/sound.c								\
		src/gameplay/check_around_towers.c		\
		src/gameplay/game_draw.c				\
		src/gameplay/game_events.c				\
		src/gameplay/game_free.c				\
		src/gameplay/game_list.c				\
		src/gameplay/game_load.c				\
		src/gameplay/game_menu.c				\
		src/gameplay/game_wave.c				\
		src/gameplay/game_towers.c				\
		src/menus/main_menu/main_draw.c			\
		src/menus/main_menu/main_events.c		\
		src/menus/main_menu/main_load.c			\
		src/menus/main_menu/main_menu.c			\
		src/menus/settings/settings_menu.c		\
		src/menus/settings/settings_load.c		\
		src/menus/settings/settings_events.c	\
		src/menus/settings/settings_draw.c		\
		src/menus/settings/credits.c			\
		src/menus/how_to_play/how_to_play.c		\
		src/menus/pause/pause_draw.c			\
		src/menus/pause/pause_events.c			\
		src/menus/pause/pause_load.c			\
		src/menus/pause/pause_menu.c			\
		src/menus/end_menu/end_draw.c			\
		src/menus/end_menu/end_events.c			\
		src/menus/end_menu/end_menu.c			\
		src/menus/end_menu/end_load.c			\
		src/init/init_map.c						\
		src/init/init_struct.c					\
		src/init/init_text.c					\
		src/loading/loading_draw.c				\
		src/loading/loading_load.c				\
		src/loading/loading.c					\
		src/utils/gen_sprite.c					\
		src/utils/get_infos.c					\
		src/utils/print_text.c					\

VPATH			=	/usr/local/lib/

OBJ			=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME 			=	my_defender

CFLAGS			=	-Wall -Wextra

CPPFLAGS		= 	-I./include/

LDFLAGS			=	-L./lib/

override LDLIBS 	+= 	-lmy -lcsfml-audio -lcsfml-system -lcsfml-graphics -lcsfml-window

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
