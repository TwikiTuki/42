# include <stdlib.h>
# include "../pushswap/push_swap.h"

t_stk_node *get_i_node(t_stk_node *stack, unsigned int i)
{
	while (stack && stack -> index != i)
		stack = stack -> next;
	return (stack);
}
int	main(int argc, char **argv)
{
	t_stk_node	*stack;
	t_stk_node	*current;
	t_stk_node	*previous;

	if (argc < 0)
		return (0);
	// Run initial tests
	if (!psw_check(argv + 1))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (argc <= 1)
		return (0);
	// Init the stack and get shure it is not null
	stack = stk_init(argv + 1, argc - 1); 
	if (!stack)
	{
		ft_printf("Error\n");
		return (0);
	}
	// Get shure the indexes are ok
	ft_printf("ordered: ");
	previous = get_i_node(stack, 0);
	ft_printf("%d:%d ", 0, previous -> value);
	for (int i = 1; i < argc ; i++)
	{
		current = get_i_node(stack, i);
		if (!current)
			break;
		if (current -> value <= previous -> value)
		{
			ft_printf("%d:%d ", i, current -> value);
			printf("Error\n");
			stk_clear(&stack);
			return (0);
		}
		ft_printf("%d:%d ", i, current -> value);
		previous = current;
	}

	stk_clear(&stack);
	ft_printf("OK\n");
}
