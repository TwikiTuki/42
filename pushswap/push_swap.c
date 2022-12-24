# include <stdlib.h>
# include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stk_node *stacks[2];

	if (argc < 1)
		return (psw_prnt_error());
	if (!psw_check(argv + 1))
		return (psw_prnt_error());
	stacks[0] = stk_init(argv + 1, argc - 1);
	if (!stacks[0])
		return (psw_prnt_error());
	stacks[1] = NULL;
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
}

int psw_prnt_error(void)
{
	ft_printf("Error\n");
	return (0);
}
