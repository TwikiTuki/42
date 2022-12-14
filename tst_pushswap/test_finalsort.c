#include "../pushswap/push_swap.h"

void test_boundaries(size_t len);
int	 check_sorted(t_stk_node *stack);

int main(int argc, char **argv)
{
	ft_printf("-------------------------\n");
	ft_printf("-------------------------\n");
	t_stk_node *stacks[2] = {NULL, NULL};

	ft_printf("Initializing stack\n");
	stacks[0] = stk_init(argv + 1, argc - 1);
	ft_printf("Stack initialized\n");
	stk_print(stacks[0]); ft_printf("\n");
	stk_print(stacks[1]); ft_printf("\n");
	ft_printf("Calling semisort\n");
	psw_semisort(stacks);
	ft_printf("Ended semisort\n");
	ft_printf("Boundaries: ");
	test_boundaries(argc - 1);

	ft_printf("Stacks: \n");
	stk_print(stacks[0]); ft_printf("\n");
	stk_print(stacks[1]); ft_printf("\n\n");

	while (stacks[1])
	{
		ft_printf("LOOPING\n");
		psw_pushback(stacks);
		ft_printf("---- Pushed back ---- \n");
		stk_print(stacks[0]); ft_printf("\n");
		stk_print(stacks[1]); ft_printf("\n\n");
		ft_printf("SORTING\n");
		psw_sorta(stacks);
		ft_printf("SORTED\n");
		stk_print(stacks[0]); ft_printf("\n");
		stk_print(stacks[1]); ft_printf("\n\n");
	}
	ft_printf("FINISHED"); check_sorted(stacks[0]); ft_printf("\n");
	stk_print(stacks[0]); ft_printf("\n");
	stk_print(stacks[1]); ft_printf("\n\n");
	ft_printf("-------------------------\n");
	ft_printf("-------------------------\n");
}

int check_sorted(t_stk_node *stack)
{
	size_t	lst_i;
	int		lst_v;

	lst_i = -1;
	lst_v = stack->value;
	while(stack)
	{
		if (stack->index != lst_i + 1 || stack->value < lst_v)
		{
			ft_printf(" <<< ERROR >>> (%d)", stack->value );
			return (0);
		}
		lst_i = stack->index;
		lst_v = stack->value;
		stack = stack->next;
	}
	return (1);
}
void test_boundaries(size_t len)
{
	size_t	start;
	size_t	boundaries[4];
	int		chunck;

	ft_printf("len %d\n", len);
	chunck = 0 - 1;
	start = 0;
	while (++chunck < CHUNCKS)
	{
		psw_boundaries(boundaries, chunck, start, len);
		start = boundaries[3] + 1;
		for (int i = 0; i < 4; i++)
			ft_printf("%d ", boundaries[i]);
		ft_printf("\n");
	}
	ft_printf("\n");
}
