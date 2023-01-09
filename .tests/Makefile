NAME := a.out

SRC_FILES := test.c printtoken.c test_utils.c ../libftprintf.a
CFLAGS ?= -Wall -Wextra -Werror -I ../header -I ../include -I ../libft
.PHONY: all clean fclean re

all: $(NAME) Makefile

$(NAME): $(SRC_FILES)
	@$(CC) $(CFLAGS) $^
	
../libftprintf.a:
	@$(MAKE) --directory=../

%.o: %.c
	@$(CC) -c $(CLAGS) -o $@ $^

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
