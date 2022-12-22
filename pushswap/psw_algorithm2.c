/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algorithm2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:56:49 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/12/22 15:11:42 by jrenau-v         ###   ########.fr       */
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
		if (stack->index > max)
			max = stack->index;	
		stack = stack->next;
	}
	if (stack->index > max)
		max = stack->index;	
	return (max) ;
}

int		psw_should_reverse(t_stk_node *stack, size_t target)
{
	size_t	len;
	size_t	position;
	
	len = stk_len(stack);
	position = 0;
	while (stack->index != target)
	{
		stack = stack->next;
		position++;
	}
	return ((len - position) < position);
}
void	psw_pushback(t_stk_node *stacks[2])
{
	long int	target;
	long int	current;
	int			reverse;

	target = stk_maxIndex(stacks[1]);
	reverse = psw_should_reverse(stacks[1], target);
	while(1)
	{
		current = stacks[1]->index;
		if (current >= target - 1)
			stk_caller(stacks, "pb");
		else if(current >= target - 3)
		{
			stk_caller(stacks, "pb");
			stk_caller(stacks, "ra");
		}
		if (current == target)
			return ;
		if (!reverse)
			stk_caller(stacks, "rb");
		else
			stk_caller(stacks, "rrb");
	}
}

void psw_sorta(t_stk_node *stacks[2])
{
	long int	nxt_target;
	long int	last;
	long int	penult;

	if(stk_len(stacks[0]) < 2)
			return ;
	last = stk_last(stacks[0])->index;
	penult = stk_last(stacks[0])->previous->index;
	if (stacks[0]->index > stacks[0]->next->index)
		stk_caller(stacks, "sa");
	nxt_target = stacks[0]->index;
	nxt_target-- ;
	if (penult == nxt_target || penult == nxt_target - 1)
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
	t_stk_node *sdaf;
	sdaf = stacks[0] -> next -> next;
}
