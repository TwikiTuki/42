NAME=pipex
SRCS=$(NAME).c	
OBJS_DIR=./objs/
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
CPP_FLAGS=-Wall -Werror -Wextra

all: $(NAME)

prnt:
	echo OBJS: $(OBJS)
	echo DEBUG: $(DEBUG)

$(NAME): $(OBJS_DIR)$(NAME).o
	$(CC) $(CPP_FLAGS) $(DEBUG) -L ./libft/ -l ft $(^) -o $(@)

objs/pipex.o: pipex.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CPP_FLAGS) $(DEBUG) -o $@ -c $< 
#$(OBJS_DIR)%.o
	




