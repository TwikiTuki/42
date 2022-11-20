OBJS_ND_DEPS=./objs_nd_deps/
NAME=libftprintf.a
SRCS=ft_flnums.c	ft_printf.c	ft_flchars.c	
OBJS=$(addprefix $(OBJS_ND_DEPS),$(SRCS:.c=.o))
DEPS=$(addprefix $(OBJS_ND_DEPS),$(SRCS:.c=.d))
OUTS=./OUTS_AND_DEPS
INCLUDE=./
WSF=-Wall -Werror -Wextra
LIB_DIR= libft

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS) 
	cd $(LIB_DIR) && make && cp libft.a ../$(NAME)
	ar rcs $@ $(OBJS) 
	
$(OBJS_ND_DEPS)%.o: %.c  
	mkdir -p  $(OBJS_ND_DEPS)   
	$(CC) -MMD $(WSF) -I $(INCLUDE) -c $< -o $@ 	 

BONUS_DIR=./bonus/
SRCS_BONUS=ft_flnums_bonus.c	ft_printf_bonus.c	ft_flchars_bonus.c	
BONUS_SRCS=$(addprefix $(BONUS_DIR)$(OBJS_ND_DEPS), $(SRCS_BONUS))
BONUS_OBJS=$(addprefix $(BONUS_DIR)$(OBJS_ND_DEPS), $(SRCS_BONUS:.c=.o))
DEPS_OBJS=$(addprefix $(BONUS_DIR), $(SRCS_BONUS:.c=.d))

bonus: $(BONUS_DIR)$(NAME)
	touch $(BONUS_DIR)bonus

$(BONUS_DIR)$(NAME): $(BONUS_OBJS)
	cd $(LIB_DIR) && make && cp libft.a ../$@
	ar rcs $@ $(BONUS_OBJS) 

#s/ft_flnums.o: ./bonus/ft_flnums.c  
$(BONUS_DIR)$(OBJS_ND_DEPS)%.o: $(BONUS_DIR)%.c  
	mkdir -p  $(BONUS_DIR)$(OBJS_ND_DEPS)   
	$(CC) -MMD $(WSF) -I $(BONUS)$(INCLUDE) -c $< -o $@ 	 

clean:
	rm -f $(OBJS) $(DEPS) 
	-cd $(LIB_DIR) fclean
	-cd $(BONUS_DIR) &&  rm -f $(OBJS) $(DEPS) 
#	cd $(BONUS_DIR) && cd $(LIB_DIR) && fclean

fclean: clean
	rm -f $(NAME)
	-rm -r  $(OBJS_ND_DEPS)
	cd $(LIB_DIR) clean
	-cd $(BONUS_DIR) && rm -f $(NAME)
	-cd $(BONUS_DIR) && rm -r  $(OBJS_ND_DEPS)
#	cd$(BONUS_DIR) cd $(LIB_DIR) clean


