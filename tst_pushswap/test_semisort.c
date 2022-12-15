#include "../pushswap/push_swap.h"

int main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	t_stk_node *stacks[2] = {NULL, NULL};

	stacks[0] = stk_init(argv + 1, argc + 1);
	stk_print(stacks[0]); ft_printf("\t");
	stk_print(stacks[1]); ft_printf("\n");
	psw_semisort(stacks);
	stk_print(stacks[0]); ft_printf("\t");
	stk_print(stacks[1]); ft_printf("\n");
}
