
NAME=push_swap
PPF= -Wall -Werror -Wextra
LIB=ft
LIB_DIR=./libft/

OBJS_ND_DEPS=./objs_nd_deps/
MAIN=push_swap.o
SRCS=psw_stk_basics.c psw_stk_operations.c psw_inpsanitize.c psw_algorithm.c psw_algorithm2.c
OBJS=$(addprefix $(OBJS_ND_DEPS), $(SRCS:.c=.o))
DEPS=$(addprefix $(OBJS_ND_DEPS), $(SRCS:.c=.d))
#OBJS=$(addprefix $(OBJS_ND_DEPS), $(SRCS:.c=.o) $(MAIN:.c=.o))
#DEPS=$(addprefix $(OBJS_ND_DEPS), $(SRCS:.c=.d) $(MAIN:.c=.d))

all: $(NAME)

prnt:
	echo NAME $(NAME)
	echo OBJS_ND_DEPS $(OBJS_ND_DEPS)
	echo OBJS $(OBJS)
	echo DEPS $(DEPS)

$(NAME): $(OBJS) $(OBJS_ND_DEPS)$(MAIN)
	make -C $(LIB_DIR)
	$(CC) $(PPF) $^ -L $(LIB_DIR) -l $(LIB) -o $(NAME) 

$(OBJS_ND_DEPS)%.o: %.c
	mkdir -p $(OBJS_ND_DEPS)
	$(CC) $(PPF) -MMD -c $< -o $@

test_sdaf2:
	ls ../tst_pushswap/

test%: $(OBJS) ../tst_pushswap/stuff/test%.o
	make -C $(LIB_DIR)
	$(CC) $(PPF) $^ -L $(LIB_DIR) -l $(LIB) -o ../tst_pushswap/stuff/$@

clean:
	-rm -rf $(OBJS_ND_DEPS)
	make -C $(LIB_DIR) fclean
	
fclean: clean
	-rm -f $(NAME)

re: fclean all


.PHONY: prnt all fclean clean re 

