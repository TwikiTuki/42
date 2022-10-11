ROOT=../
PR_DIR=./ft_printf/
TS_DIR=./tst_ft_printf/
WFS= -Wall -Werror -Wextra
LIBS=ftprintf
PR_NAME=ft_printf
NAME=test.exe

all:
	cd $(ROOT)$(PR_DIR); make re
	$(CC) $(WFS) $(NAME) -L$(ROOT)$(PR_DIR) -l$(LIBS) -o$(NAME) test.c
	./$(NAME)
