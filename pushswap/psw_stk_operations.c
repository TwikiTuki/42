/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_stk_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:35:54 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/12/20 17:24:45 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	stk_caller(t_stk_node *stacks[2], char *action)
{
	int s;
	
//	if (action[0] == 'p' && action[1] == 'a')
//		ft_printf("%s\n", "pb");
//	else if (action[0] == 'p' && action[1] == 'b')
//		ft_printf("%s\n", "pa");
	//else
		ft_printf("%s\n", action);
	s = (ft_strlen(action) == 2 && action[1] == 'b') || 
			(ft_strlen(action) == 3 && action[2] == 'b');
	if (action[0] == 's' && action[1] != 's')
		stk_swap(stacks[s]);
	else if (!ft_strncmp(action, "ss", 2))
	{
		stk_swap(stacks[0]);
		stk_swap(stacks[1]);
	}
	else if (action[0] == 'p')
		stk_push(&stacks[s], &stacks[!s]);
	else if ((!action[2] && action[1] == 'r') || (action[2] && action[2] == 'r')) 
	{
		stk_rotate(&stacks[0], ft_strlen(action) == 3);
		stk_rotate(&stacks[1], ft_strlen(action) == 3);
	}	
	else if (action[0] == 'r')
		stk_rotate(&stacks[s], ft_strlen(action) == 3);
}

void stk_push(t_stk_node **stk2, t_stk_node **stk1)
{
	t_stk_node *moved;

	if (!*stk1)
		return ;
	moved = *stk1;
	(*stk1)->previous = NULL;
	*stk1 = (*stk1)->next;
	if (*stk2)
	{
		moved->next = *stk2;
		(*stk2)->previous = moved;
	}
	else
		moved->next = NULL;
	*stk2 = moved;
}

void stk_swap(t_stk_node *stk)
{
	int aux;
	if (stk && stk->next)
	{
		aux = stk->value;
		stk->value = stk->next->value;
		stk->next->value = aux;
		aux = stk->index;
		stk->index = stk->next->index;
		stk->next->index = aux;
	}
}

void stk_rotate(t_stk_node **stk, int reverse)
{
	t_stk_node *last;
	if (!*stk)
		return ;
	last = stk_last(*stk);
	if (!reverse)
	{
		if ((*stk)->next)
		{
			last->next = *stk;
			(*stk)->previous = last;
			*stk = (*stk)->next;
			(*stk)->previous->next = NULL;
			(*stk)->previous = NULL;
		}
	}
	else if (reverse)
	{
		if ((*stk)->next) 
		{
			last->next = *stk;
			last->previous->next = NULL;
			last->previous = NULL;
			(*stk)->previous = last;
			*stk = last;
		}
	}
}
