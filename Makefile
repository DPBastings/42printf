# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dbasting <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/21 11:29:16 by dbasting      #+#    #+#                  #
#    Updated: 2022/12/28 17:01:33 by dbasting      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRC_DIR := 	./sources/
OBJ_DIR := 	./objects/
HEADER_DIR := ./headers/
LIB_DIR := ./libft/
SRC_FILES := ft_printf.c\
	carriage.c\
	expand_token.c\
	misc.c\
	padding.c\
	parser.c\
	parser_conversion.c\
	printchr.c\
	printdec.c\
	printhex.c\
	printlit.c\
	printoct.c\
	printstr.c\
	token.c
OBJ_FILES := $(SRC_FILES:.c=.o)
HEADER_FILES := libftprintf.h\
	carriage.h\
	misc.h\
	token.h
LIB_FILES := libft.a

CFLAGS ?= -Wall -Wextra -Werror -I $(HEADER_DIR) -I $(LIB_DIR)
AFLAGS ?= -rc
.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: all
	@echo "Bonus is basis, vrind."
	
$(NAME): $(addprefix $(OBJ_DIR),$(OBJ_FILES))
	@$(MAKE) --directory=$(LIB_DIR)
	@ar $(AFLAGS) $@ $^
	@mkdir -p .temp/
	@cd .temp/ &&\
	ar -x $(addprefix ../$(LIB_DIR),$(LIB_FILES)) &&\
	cd ..
	@ar $(AFLAGS) $@ ./.temp/*.o
	@rm -rf ./.temp/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(addprefix $(HEADER_DIR),$(HEADER_FILES))
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@rm -f $(OBJ_DIR)*.o
	@$(MAKE) --directory=$(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --directory=$(LIB_DIR) fclean

re: fclean all
