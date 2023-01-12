# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dbasting <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/21 11:29:16 by dbasting      #+#    #+#                  #
#    Updated: 2023/01/09 17:04:39 by dbasting      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRC_DIR := ./source/
OBJ_DIR := ./object/
HDR_DIR := ./header/
INC_DIR := ./include/

SRC_FILES := ft_printf.c\
	carriage.c\
	expand_token.c\
	misc_alloc.c\
	misc_atoi.c\
	misc_string.c\
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
HDR_FILES := carriage.h\
	misc.h\
	token.h
INC_FILES := libftprintf.h

CFLAGS ?= -Wall -Wextra -Werror -I$(HDR_DIR) -I$(INC_DIR)
AFLAGS ?= -rc
.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: all
	@echo "Bonus is basis, vrind."
	
$(NAME): $(addprefix $(OBJ_DIR),$(OBJ_FILES))
	#@$(MAKE) --directory=$(LIB_DIR)
	@ar $(AFLAGS) $@ $^
	#@mkdir -p .temp/
	#@cd .temp/ &&\
	#ar -x $(addprefix ../$(LIB_DIR),$(LIB_FILES)) &&\
	#cd ..
	#@ar $(AFLAGS) $@ ./.temp/*.o
	#@rm -rf ./.temp/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(addprefix $(HDR_DIR),$(HDR_FILES))
	@mkdir -p $(OBJ_DIR)
	@$(CC) $< $(CFLAGS) -c -o $@

clean:
	@rm -f $(OBJ_DIR)*.o
	#@$(MAKE) --directory=$(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	#@$(MAKE) --directory=$(LIB_DIR) fclean

re: fclean all
