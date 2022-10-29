NAME=libftprintf.a
SRCS=ft_printf.c ft_flchars.c ft_flnums.c
OBJS=$(SRCS:.c=.o)
DEPS=$(SRCS:.c=.d)
OUTS=./OUTS_AND_DEPS
INCLUDE=./
WSF=-Wall -Werror -Wextra
LIB_MAKE= cd libft && make

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS) 
	$(LIB_MAKE)
	ar rcs $@ $(OBJS) ./libft/ft_strchr.o ./libft/ft_strlen.o ./libft/ft_strdup.o ./libft/ft_bzero.o

%.o: %.c 
	$(CC) -MMD $(WSF) -I $(INCLUDE) -c $< -o $@ 	 

clean:
	rm -f $(OBJS) $(DEPS) 
	$(LIB_MAKE) fclean

fclean: clean
	rm -f $(NAME)
	$(LIB_MAKE) clean

re: fclean all

.PHONY: clean fclean all re
