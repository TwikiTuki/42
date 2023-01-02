# include <stdlib.h>
# include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stk_node *stacks[2];

	if (argc <= 1)
		return (0);
	if (!psw_check(argv + 1))
		return (psw_prnt_error());
	stacks[0] = stk_init(argv + 1, argc - 1);
	if (!stacks[0])
		return (psw_prnt_error());
	stacks[1] = NULL;
	if (argc <= 2)
	{
		stk_clear(&stacks[0]);
		return (0);
	}
	if (stk_len(stacks[0]) <= 3)
		stk_size3(stacks);
	else
	{
		psw_semisort(stacks);
		while (stacks[1])
		{
			psw_pushback(stacks);
			psw_sorta(stacks);
		}
	}
	stk_clear(&stacks[0]);
}

int psw_prnt_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}
