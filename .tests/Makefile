NAME := a.out

SRC_FILES := test_pct.c printtoken.c test_utils.c ../libftprintf.a
CFLAGS ?= -Wall -Wextra -Werror
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
