ROOT=../
PR_DIR=./ft_printf/
TS_DIR=./tst_ft_printf/
WFS= -Wall -Werror -Wextra
LIBS=ftprintf
PR_NAME=ft_printf
NAME=test.exe

all:
	cd $(ROOT)$(PR_DIR); make
	$(CC) -fsanitize=address $(WFS) -L$(ROOT)$(PR_DIR) -l$(LIBS) -L$(ROOT)$(PR_DIR)/libft/ -lft -o$(NAME) test.c
	./$(NAME)

.PHONY: all
