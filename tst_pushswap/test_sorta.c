#include "../pushswap/push_swap.h"

int main(int argc, char **argv)
{
	//t_stk_node	*stacka;	
	t_stk_node	*stacks[2];

	ft_printf("Initializing stacks\n");
	stacks[0] = stk_init(argv + 1, argc - 1 );
	ft_printf("Stacka: "); stk_print(stacks[0]);
	ft_printf("\n");
	stacks[1] = NULL;
	psw_sorta(stacks);	
	stacks[0] = stacks[0];
	ft_printf("Stacka at out: ");
	stk_print(stacks[0]);
	//ft_printf("  0)  %p: %p, val: %d\n  ", &stacks[0], stacks[0], stacks[0]->value);
	//ft_printf("1)  %p: %p\n", &stacks[1], stacks[1]);

	t_stk_node *real_start;
	//ft_printf("\nstacks in outter:\n");
	//ft_printf("sdaaf\n");
	real_start = stacks[0]->previous;
	ft_printf("\n");
	ft_printf("\n");

}
