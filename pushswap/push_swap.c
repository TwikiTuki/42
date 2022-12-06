# include <stdlib.h>
# include "push_swap.h"

void	print_stacks(t_stk_node *stack1, t_stk_node *stack2);
void	test(int argc, char **argv);
void	test_nulls(int argc, char **argv);
void	frm2_toNll_to2(int argc, char **argv);

int		main(int argc, char **argv)
{
	test(argc, argv);
	test_nulls(argc, argv);
	frm2_toNll_to2(argc, argv);
}

void	test_nulls(int argc, char **argv)
{
	t_stk_node *stk1;
	t_stk_node *stk2;

	ft_printf("TESTING NULLS\n");
	stk1 = NULL;
	stk2 = NULL;

	stk1 = stk_init(argv + 1, argc - 1);
	
	print_stacks(stk1, stk2);
	ft_printf("pushing NULL to NULL\n");
	stk_push(&stk1, &stk2);
	print_stacks(stk1, stk2);
	ft_printf("pushed NULL to NULL\n");
	ft_printf("\n");

	stk_push(&stk2, &stk1);
	print_stacks(stk1, stk2);
	ft_printf("pushing NULL to SMTH\n");
	stk_push(&stk2, &stk1);
	print_stacks(stk1, stk2);
	ft_printf("pushed NULL to SMTH\n");
	ft_printf("\n");

	print_stacks(stk1, stk2);
	ft_printf("pushing SMTH to NULL\n");
	stk_push(&stk1, &stk2);
	print_stacks(stk1, stk2);
	ft_printf("pushed SMTH to NULL\n");
	ft_printf("\n");

	ft_printf("\nend\n");


}

void frm2_toNll_to2(int argc, char **argv)
{
	t_stk_node *stk1;
	t_stk_node *stk2;
	ft_printf("\nEmmpting and populating stacks\n");
	stk1 = NULL;
	stk2 = NULL;

	stk1 = stk_init(argv + 1, argc - 1);

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i <= argc; i++)
		{
			stk_push(&stk1, &stk2);
		}
		print_stacks(stk1, stk2);
		for (int i = 0; i <= argc; i++)
		{
			stk_push(&stk2, &stk1);
		}
		print_stacks(stk1, stk2);
	}
	ft_printf("\nend\n");
}

void test(int argc, char **argv)
{
	t_stk_node *stack;
	t_stk_node *stack_aux;

	ft_printf("\nmain tests\n");
	stack = NULL;
	stack_aux = NULL;
	stack = stk_init(argv + 1, argc - 1);
	ft_printf("\n");
	stk_print(stack); ft_printf("\n");
	
	ft_printf("\n");
	ft_printf("Rotating: \n");
	stk_rotate(&stack, 0);
	stk_print(stack); ft_printf("\n");
	stk_rotate(&stack, 0);
	stk_print(stack); ft_printf("\n");
	stk_rotate(&stack, 0);
	stk_print(stack); ft_printf("\n");

	ft_printf("Reverse rotating: \n");
	stk_rotate(&stack, 1);
	stk_print(stack); ft_printf("\n");
	stk_rotate(&stack, 1);
	stk_print(stack); ft_printf("\n");
	stk_rotate(&stack, 1);
	stk_print(stack); ft_printf("\n");
	ft_printf("\n");

	ft_printf("Swapping:\n");
	ft_printf("\n");
	stk_swap(stack);
	stk_print(stack); ft_printf("\n");
	stk_swap(stack);
	stk_print(stack); ft_printf("\n");
	
	ft_printf("pushing:\n");
	print_stacks(stack, stack_aux);

//	stk_push(&stack_aux, &stack); 
	print_stacks(stack, stack_aux);

	ft_printf("passed first NULL\n");

	stk_push(&stack, &stack_aux);
	print_stacks(stack, stack_aux);
	stk_push(&stack, &stack_aux);
	print_stacks(stack, stack_aux);
	stk_push(&stack, &stack_aux);
	print_stacks(stack, stack_aux);

	stk_push(&stack_aux, &stack); 
	print_stacks(stack, stack_aux);
	stk_push(&stack_aux, &stack); 
	print_stacks(stack, stack_aux);
}

void print_stacks(t_stk_node *stack1, t_stk_node *stack2)
{
	ft_printf("Stack1: ");
	stk_print(stack1);
	ft_printf(" Stack2: ");
	stk_print(stack2);
	ft_printf("\n");
}
