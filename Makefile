NAME := libftprintf.a

SRC_DIR := 		./sources/
OBJ_DIR := 		./objects/
HEADER_DIR := 	./headers/
LIB_DIR := 		./libft/
SRC_FILES :=	ft_printf.c\
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
				printstr.c
OBJ_FILES := 	$(SRC_FILES:.c=.o)
HEADER_FILES := libftprintf.h\
				carriage.h\
				misc.h\
				token.h
CFLAGS ?= 		-Wall -Wextra -Werror -I $(HEADER_DIR)
SRC_FILES := 	$(SRC_FILES:%=$(SRC_DIR)%)
OBJ_FILES :=	$(OBJ_FILES:%=$(OBJ_DIR)%)
HEADER_FILES :=	$(HEADER_FILES:%=$(HEADER_DIR)%)

PHONY: all bonus clean fclean re

all: $(NAME)

bonus: all
	@echo "Bonus is basis, vrind."
	
$(NAME): $(OBJ_FILES)
	@$(MAKE) --directory=$(LIB_DIR)
	@ar -rcu $@ $< libft/libft.a

%.o: %.c $(HEADER_FILES)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@rm -f $(OBJ_DIR)*.o
	@$(MAKE) --directory=$(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --directory=$(LIB_DIR) fclean

re: fclean all