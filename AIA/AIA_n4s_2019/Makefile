##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

define rich_echo
[ -t 1 ] && echo -e "\e[1m$(1)\e[0m\t$(2)" || echo -e "$(1)\t$(2)"
endef

MAKEFLAGS += --no-print-directory

CC				= gcc
MAKE			= make

SOURCE_DIR		= src
BUILD_DIR		= build

SOURCE	= $(shell find $(SOURCE_DIR) -name "*.c")

CFLAGS	+=	-Iinclude -W

ifneq (,$(findstring debug,$(MAKECMDGOALS)))
	CFLAGS += -D__DEBUG__ -g3
endif

ifneq (,$(findstring tests,$(MAKECMDGOALS)))
	CFLAGS += -D__TESTS -lcriterion --coverage
endif

OBJ		=	$(patsubst $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCE))

NAME	=	ai

all:	$(NAME) message #test_run

debug: all

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	@$(call rich_echo,"CC","$@")
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

message:
	@echo -e "\e[38;5;33m"
	@figlet $(NAME); exit 0
	@echo -e "\e[0m"
	@echo -e "\e[1m[INFO]\t\e[92mCompilation successful ✔\e[0m"

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@rm -rf tests/*.gc*
	@rm -rf *.gc*
	@$(call rich_echo,"MK","FClean done")

fclean:		clean
	@rm -f $(NAME)*
	@$(call rich_echo,"AA","Assets compressed")
	@$(call rich_echo,"MK","FClean done")

re:	fclean all

protos: $(NAME)
	@cproto $(SOURCE) -Iinclude

tests_run:
	@$(CC) -o $(NAME)_tests $(SOURCE) tests/*.c $(CFLAGS) $(LD_FLAGS)
	@$(call rich_echo,"UT","Unit tests compilation done.")
	@./$(NAME)_tests
	@mv *.gc* tests/

.PHONY: tests_run re fclean clean all $(NAME) protos message
.NOTPARALLEL: