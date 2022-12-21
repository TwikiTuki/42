#include "../pushswap/push_swap.h"

int main(int argc, char **argv)
{
	t_stk_node	*stacka;	
	t_stk_node	*stacks[2];

	ft_printf("Initializing stacks\n");
	stacka = stk_init(argv + 1, argc - 1 );
	ft_printf("Stacka: "); stk_print(stacka);
	ft_printf("\n");
	stacks[0] = stacka; stacks[1] = NULL;
	psw_sorta(stacks);	
	ft_printf("Stacka at end: "); stk_print(stacka);
	ft_printf("\n");
	ft_printf("\n");
}
