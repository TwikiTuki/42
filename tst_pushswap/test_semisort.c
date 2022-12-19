#include "../pushswap/push_swap.h"

int main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	t_stk_node *stacks[2] = {NULL, NULL};

	ft_printf("Initializing stack\n");
	stacks[0] = stk_init(argv + 1, argc - 1);
	ft_printf("Stack initialized\n");
	stk_print(stacks[0]); ft_printf("\n");
	stk_print(stacks[1]); ft_printf("\n");
	ft_printf("Calling semisort\n");
	psw_semisort(stacks);
	ft_printf("Ended semisort\n");
	stk_print(stacks[0]); ft_printf("\n");
	stk_print(stacks[1]); ft_printf("\n");
}
