#include "../pushswap/push_swap.h"

void test_boundaries(size_t len);
void	big_test(int argc, char **argv);
void	prepared_test(void);

int main(int argc, char **argv)
{
	if(artgc > 1)
	{
		big_test(argc, argv);
		return (0);
	}
	prepared_test((int[])  {1,2,3,4}, 4);
	
}

void	big_test(int argc, char **argv)
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
	ft_printf("Boundaries: ");
	test_boundaries(argc - 1);

	ft_printf("Stacks: \n");
	stk_print(stacks[0]); ft_printf("\n");
	stk_print(stacks[1]); ft_printf("\n");
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
