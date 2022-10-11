NAME=bftprintf.a
SRCS=ft_printf.c
OBJS=$(SRCS:.c=.o)
DEPS=$(SRCS:.c=.d)
OUTS=./OUTS_AND_DEPS
INCLUDE=./
WSF=-Wall -Werror -Wextra

all: $(NAME)
-include $(DEPS)

$(NAME): $(OBJS) 
	ar rcs $@ $(OBJS)
%.o: %.c 
	$(CC) -MMD $(WSF) -I $(INCLUDE) -c $< -o $@ 	 
clean:
	rm -f $(OBJS) $(DEPS)
flcean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: clean fclean all re
