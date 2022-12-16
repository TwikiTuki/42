/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_stk_basics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:38:30 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/12/15 20:11:09 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# include "push_swap.h"

t_stk_node 	*stk_last(t_stk_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}
t_stk_node  *stk_clear( t_stk_node **stack)
{
	t_stk_node *node;
	t_stk_node *next;

	node = *stack;
	*stack = NULL;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	return (NULL);
}

t_stk_node *stk_init(char **numbers, size_t len)
{
	t_stk_node	*nw_node;
	t_stk_node	*lst_node;

	nw_node = NULL;
	lst_node = NULL;
	while (len--)
	{
		nw_node = malloc(sizeof (t_stk_node));	
		if (!nw_node)
			return (NULL); 
		nw_node->value = ft_atoi(numbers[len]);
		nw_node->previous = NULL;
		if (!lst_node)
			nw_node->next = NULL;	
		else
		{
			nw_node->next = lst_node;
			lst_node->previous = nw_node;
		}
		lst_node = nw_node;
	}
	psw_getindexes(&nw_node);
	return (nw_node);
}

void	stk_print(t_stk_node	*stk)
{
	size_t	bnds[4];
	size_t	i;
	int		chunck;

	if (stk == NULL)
	{
		ft_printf("(empty)");
		return ;
	}

	i = 0;
	psw_boundaries(bnds, 0, 0, stk_len(stk));
	while (stk)
	{
		if (i == bnds[0] || i == bnds[1] || i == bnds[2] || i == bnds[3])
			ft_printf("*");
		if (i == bnds[3])
		{
			ft_printf("*");
			chunck++;
			psw_boundaries(bnds, chunck, bnds[3] + 1, stk_len(stk)); 
		}
		ft_printf("%d:%d ", stk->index, stk->value);
		i++;
		stk = stk->next;
	}
}

int psw_getindexes(t_stk_node **start)
{
	t_stk_node	*to_sort;
	t_stk_node	*to_cmpr;		
	
	to_sort = *start;
	while (to_sort)
	{
		to_sort -> index = 0;
		to_cmpr = *start; 
		while (to_cmpr)
		{
			if (to_sort -> value >  to_cmpr -> value)
				to_sort -> index += 1;
			if (to_sort -> value == to_cmpr -> value && to_sort != to_cmpr) 
			{
				stk_clear(start);
				return (0);
			}
			to_cmpr = to_cmpr -> next;
		}
		to_sort = to_sort -> next;
	}
	return (1);
}
