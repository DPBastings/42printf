NAME := libftprintf.a

SRC_FILES := ft_printf.c
OBJ_FILES := $(SRC_FILES:.c=.o)
HEADER_FILES := libftprintf.h
SRC_DIR := ./sources/
OBJ_DIR := ./objects/
HEADER_DIR := ./headers/
LIB_DIR := ./libft/
CFLAGS ?= -Wall -Wextra -Werror
.PHONY: all bonus clean fclean re

all: $(NAME)

bonus:
	@echo "Er is nog geen bonus..."

$(NAME): $(OBJ_FILES:%=$(OBJ_DIR)%)
	@$(MAKE) --directory=$(LIB_DIR)
	@ar -rcu $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c #$(HEADER_FILES:%=$(HEADER_DIR)%)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@rm -f $(OBJ_DIR)*.o
	@$(MAKE) --directory=$(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --directory=$(LIB_DIR) fclean

re: fclean all
