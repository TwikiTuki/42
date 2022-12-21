/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algorithm2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:56:49 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/12/21 19:48:00 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_stk_node *stacks[2])
{
	while (stacks[1])
	{
		psw_pushback(stacks);
		psw_sorta(stacks);
		ft_printf("stack[0] after psw_sorta");
		stk_print(stacks[0]);
		ft_printf("\n");
	}
}

size_t stk_maxIndex(t_stk_node *stack)
{
	size_t	max;

	max = 0;
	while (stack->next)
	{
		if (stack->index < max)
			max = stack->index;	
		stack = stack->next;
	}
	return (stack->index) ;
}
void	psw_pushback(t_stk_node *stacks[2])
{
	long int	target;
	long int	current;

	//if (stacks[0])	
	//	target = stacks[0]->index - 1;
	target = stk_maxIndex(stacks[1]);
	while(1)
	{
		/*
		ft_printf("l: %d target: %d \t\t", len, target);
		ft_printf("%p, %p\n<<<", stacks[0], stacks[1]);
		stk_print(stacks[0]);
		ft_printf(">>> <<<");
		stk_print(stacks[1]);
		ft_printf(">>>\n");
		*/
			
		current = stacks[1]->index;
		if (current >= target - 1)
		{
			stk_caller(stacks, "pb");
			stk_print(stacks[0]); ft_printf(" || "); stk_print(stacks[1]); ft_printf("\n");
		}
		else if(current >= target - 3)
		{
			stk_caller(stacks, "pb");
			stk_caller(stacks, "ra");
			stk_print(stacks[0]); ft_printf(" || "); stk_print(stacks[1]); ft_printf("\n");
		}
		if (current == target)
			return ;
		//ft_printf("Ending while\n");
		stk_caller(stacks, "rb");
	}
}

void psw_sorta(t_stk_node *stacks[2])
{
	long int	nxt_target;
	long int	last;
	long int	penult;
	last = stk_last(stacks[0])->index;
	penult = stk_last(stacks[0])->previous->index;
	if (stacks[0]->index > stacks[0]->next->index)
		stk_caller(stacks, "sa");
	nxt_target = stacks[0]->index;
	nxt_target-- ;
	ft_printf("stk[0]: %d, nxt: %d, penult: %d, last: %zu\n",stacks[0]->index,  nxt_target, penult, last);
	if (penult == nxt_target || penult == nxt_target - 1) // Penult may be NULL
	{
		stk_caller(stacks, "rra");
		stk_caller(stacks, "rra");
	}
	else if (last == nxt_target || last == nxt_target - 1)	
		stk_caller(stacks, "rra");
	if (stacks[0]->index > stacks[0]->next->index)
		stk_caller(stacks, "sa");
	if (stacks[0]->index + 1 < nxt_target)
		stk_caller(stacks, "ra");
	ft_printf("stacka end func");
	stk_print(stacks[0]);
	ft_printf("\n");
}
