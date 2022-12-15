# include <stdlib.h>
# include "../pushswap/push_swap.h"

void	print_stacks(t_stk_node *stack1, t_stk_node *stack2);
void	test(int argc, char **argv);
void	test_nulls(int argc, char **argv);
void	frm2_toNll_to2(int argc, char **argv);

int		main(int argc, char **argv)
{
	ft_printf("\n<<< MAIN TEST >>>\n");
	test(argc, argv);
	ft_printf("\n");
	test_nulls(argc, argv);
	ft_printf("\n");
	frm2_toNll_to2(argc, argv);
	ft_printf("\n");
}

void	test_nulls(int argc, char **argv)
{
	t_stk_node stacks[2] = {NULL, NULL};

	ft_printf("<<< TESTING NULLS >>>\n");

	stacks[0] = stk_init(argv + 1, argc - 1);
	
	print_stacks(stacks[0], stacks[1]);
	ft_printf("pushing NULL to NULL\n");
	stk_push(&stacks[0], &stacks[1]);
	print_stacks(stacks[0], stacks[1]);
	ft_printf("pushed NULL to NULL\n");
	ft_printf("\n");

	stk_push(&stacks[1], &stacks[0]);
	print_stacks(stacks[0], stacks[1]);
	ft_printf("pushing NULL to SMTH\n");
	stk_push(&stacks[1], &stacks[0]);
	print_stacks(stacks[0], stacks[1]);
	ft_printf("pushed NULL to SMTH\n");
	ft_printf("\n");

	print_stacks(stacks[0], stacks[1]);
	ft_printf("pushing SMTH to NULL\n");
	stk_push(&stacks[0], &stacks[1]);
	print_stacks(stacks[0], stacks[1]);
	ft_printf("pushed SMTH to NULL\n");
	ft_printf("\n");
}

void frm2_toNll_to2(int argc, char **argv)
{
	t_stk_node stacks[2] = {NULL, NULL};
	ft_printf("\nEmmpting and populating stacks\n");
	stacks[0] = stk_init(argv + 1, argc - 1);

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i <= argc; i++)
		{
			stk_push(&stacks[0], &stacks[1]);
		}
		print_stacks(stacks[0], stacks[1]);
		for (int i = 0; i <= argc; i++)
		{
			stk_push(&stacks[1], &stacks[0]);
		}
		print_stacks(stacks[0], stacks[1]);
	}
}

void test_rotate(int argc, char **argv)
{
	t_stk_node stacks[2] = {NULL, NULL};
	
	stacks[0] = stk_init(argv + 1, argc - 1);
	stacks[1] = stk_init(argv + 1, argc - 1);
	ft_printf("Initialized: \n");
	stk_print(stacks[0]); ft_printf("\t");
	stk_print(stacks[1]); ft_printf("\n");
	ft_printf("Rotating separated\n");
	for (int i = -1; i <= argc; i++)
	{
		stk_caller(stacks, "ra");
		stk_caller(stacks, "rb");
		stk_print(stacks[0]); ft_printf("\t");
		stk_print(stacks[1]); ft_printf("\n");
	}
	ft_printf("Rotating together\n");
	for (int i = -1; i <= argc; i++)
	{
		stk_caller(stacks, "rr");
		stk_print(stacks[0]); ft_printf("\t");
		stk_print(stacks[1]); ft_printf("\n");
	}

	ft_printf("Reverse rotating separated: \n");
	for (int i = -1; i <= argc; i++)
	{
		stk_caller(stacks, "rra");
		stk_caller(stacks, "rrb");
		stk_print(stacks[0]); ft_printf("\t");
		stk_print(stacks[1]); ft_printf("\n");
	}
	ft_printf("Reverse rotating together: \n");
	for (int i = -1; i <= argc; i++)
	{
		stk_caller(stacks, "rrr");
		stk_print(stacks[0]); ft_printf("\t");
		stk_print(stacks[1]); ft_printf("\n");
	}
}

void test_swap(int argc, char **argv)
{
	t_stk_node stacks[2] = {NULL, NULL};
	stacks[0] = stk_init(argv + 1, argc - 1);
	stacks[1] = stk_init(argv + 1, argc - 1);

	ft_printf("Initialized: \n");
	stk_print(stacks[0]); ft_printf("\t");
	stk_print(stacks[1]); ft_printf("\n");
	ft_printf("Swapping separated: \n");
	for (int i = 0; i < 4; i++)
	{
		stk_caller(stacks, "sa");
		stk_caller(stacks, "sb"); 
		stk_print(stacks[0]); ft_printf("\t");
		stk_print(stacks[1]); ft_printf("\n");
	}
	ft_printf("Swapping together: \n");
	for (int i = 0; i < 4; i++)
	{
		stk_caller(stacks, "ss");
		stk_print(stacks[0]); ft_printf("\t");
		stk_print(stacks[1]); ft_printf("\n");
	}
}

void test_push(int argc, char **argv)
{
	t_stk_node stacks[2] = {NULL, NULL};
	stacks[0] = stk_init(argv + 1, argc - 1);
	
	ft_printf("Initialized: \n");
	stk_print(stacks[0]); ft_printf("\t");
	stk_print(stacks[1]); ft_printf("\n");
	ft_printf("Pushing pa\n");
	for (int i =  0; i <= argc; i++)
	{
		stk_caller(stacks, "pa");
		stk_print(stacks[0]); ft_printf("\t");
		stk_print(stacks[1]); ft_printf("\n");
	}
	ft_printf("Pushing pb\n");
	for (int i =  0; i <= argc; i++)
	{
		stk_caller(stacks, "pb");
		stk_print(stacks[0]); ft_printf("\t");
		stk_print(stacks[1]); ft_printf("\n");
	}
}

void test(int argc, char **argv)
{
	t_stk_node stacks[2] = {NULL, NULL};
	
	// TESTING ROTATE
	ft_printf("<<<Rotating:>>>\n");
	test_rotate(argc - 1, argv + 1);
	ft_printf("\n");

	// SWAPING
	ft_printf("<<<Swapping:>>>\n");
	test_swap(argc - 1, argv + 1);
	print_stacks(stacks[0], stacks[1]);

	// PUSHING
	ft_printf("\n<<<Pushing:>>>\n");
	test_push(argc, argv);
}

void print_stacks(t_stk_node *stack1, t_stk_node *stack2)
{
	ft_printf("Stack1: ");
	stk_print(stack1);
	ft_printf("Stack2: ");
	stk_print(stack2);
	ft_printf("\n");
}
