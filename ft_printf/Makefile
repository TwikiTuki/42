NAME=libftprintf.a
LIBFT=
OBJS_ND_DEPS=./objs_nd_deps/
SRC=ft_flchars.c ft_flnums.c ft_printf.c
OBJS=$(addprefix $(OBJS_ND_DEPS), $(SRC:.c=.o))
DEPS=$(addprefix $(BJS_ND_DEPS), $(SRC:.c=.d))
LIBFT_DIR=./libft/
WSF=-Wall -Werror -Wextra

-include $(DEPS)
-include $(BONUS_DEPS)

$(NAME): $(OBJS) $(LIBFT_DIR)/*
	cd $(LIBFT_DIR) && make && cp libft.a ../$(NAME)
	ar -rc $(@) $(OBJS)
$(LIBF_DIR)%: ;

$(OBJS_ND_DEPS)%.o: %.c ft_printf.h Makefile
	mkdir -p $(OBJS_ND_DEPS)
	$(CC) -MMD $(WSF) -c -o$@ $<

BONUS_DIR=./bonus/
BONUS_SRC=ft_flchars_bonus.c ft_flnums_bonus.c ft_printf_bonus.c
BONUS_OBJS=$(addprefix $(BONUS_DIR)$(OBJS_ND_DEPS), $(BONUS_SRC:.c=.o))
BONUS_DEPS=$(addprefix $(BONUS_DIR)$(BJS_ND_DEPS), $(BONUS_SRC:.c=.d))

bonus: $(BONUS_OBJS) $(BONUS_DIR) $(LIBFT_DIR)/*
	touch $(BONUS_DIR)bonus
	cd $(LIBFT_DIR) && make && cp libft.a ../$(BONUS_DIR)$(NAME)
	ar -rc $(BONUS_DIR)$(NAME) $(BONUS_OBJS)

$(BONUS_DIR)$(OBJS_ND_DEPS)%.o: $(BONUS_DIR)%.c $(BONUS_DIR)ft_printf_bonus.h Makefile
	mkdir -p $(BONUS_DIR)$(OBJS_ND_DEPS)
	$(CC) -MMD $(WSF) -o $(@) -c $(<)

clean:
	-rm -r $(OBJS_ND_DEPS)
	-rm -r $(BONUS_DIR)$(OBJS_ND_DEPS)

fclean: clean
	-rm $(NAME)
	-rm $(BONUS_DIR)$(NAME)

prnt:
	echo $(OBJS_ND_DEPS)
	echo $(BONUS_OBJS)

.PHONY: clean fclean
