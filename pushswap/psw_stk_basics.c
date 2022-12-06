# include "push_swap.h"

t_stk_node 	*stk_last(t_stk_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}
t_stk_node  *stk_clear( t_stk_node **stack)
{
	t_stk_node *node;
	t_stk_node *next;

	node = *stack;
	*stack = NULL;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	return (NULL);
}

t_stk_node *stk_init(char **numbers, size_t len)
{
	t_stk_node	*nw_node;
	t_stk_node	*lst_node;

	nw_node = NULL;
	lst_node = NULL;
	while (len--)
	{
		nw_node = malloc(sizeof (t_stk_node));	
		if (!nw_node)
			return (NULL); 
		nw_node->value = ft_atoi(numbers[len]);
		nw_node->previous = NULL;
		if (!lst_node)
			nw_node->next = NULL;	
		else
		{
			nw_node->next = lst_node;
			lst_node->previous = nw_node;
		}
		lst_node = nw_node;
	}
	return (nw_node);
}

void	stk_print(t_stk_node	*stk)
{
	if (stk == NULL)
	{
		ft_printf("(empty)");
		return ;
	}

	while (stk)
	{
		ft_printf("%d ", stk->value);
		stk = stk->next;
	}
}
