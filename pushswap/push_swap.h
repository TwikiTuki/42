#include <stdio.h>
#include "./libft/ft_printf/ft_printf.h"
#include "./libft/libft/libft.h"

typedef struct s_stk_node
{
	int					value;
	struct s_stk_node	*previous;
	struct s_stk_node	*next;
} t_stk_node;

/*psw_stk_basics.c*/
t_stk_node *stk_last(t_stk_node *stack);
t_stk_node *stk_clear(t_stk_node **stack);
t_stk_node *stk_init(char **numbers, size_t len);
void stk_print(t_stk_node *stk);

/*psw_stk_operions*/
void stk_push(t_stk_node **stk1, t_stk_node **stk2);
void stk_swap(t_stk_node *stk);
void stk_rotate(t_stk_node **stk, int reverse);
