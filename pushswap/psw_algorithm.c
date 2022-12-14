/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algrothm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:12:51 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/12/20 10:55:57 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	psw_boundaries(size_t bounds[], int chunck, size_t start_d, size_t ln)
{
	unsigned int	size;
	unsigned int	size_up;
	unsigned int	size_down;

	size = ln / CHUNCKS + ((size_t) chunck < (ln % CHUNCKS));
	size_up = size / 2;
	size_down = size / 2 + size % 2;
	bounds[0] = start_d;
	bounds[2] = bounds[0] + size_down - 1;
	bounds[1] = bounds[2] + 1;
	bounds[3] = bounds[1] + size_up - 1;
}	

/*
void	rotate_b(t_stk_node *stacks[], int up, int target)
{
	if (up == target)
		return ;
	if (target)
		stk_caller(stacks, "rrb");
	else
		stk_caller(stacks, "rb");
}
*/

size_t	stk_len(t_stk_node *stack)
{
	size_t	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack -> next;
	}
	return (len);
}

void	psw_semisort(t_stk_node *stacks[])
{
	size_t			bounds[4];
	size_t			len;
	size_t			orig_len;
	int				chunck;	
	
	chunck = 0;
	bounds[3] = 0 - 1;
	orig_len = stk_len(stacks[0]);
	while (chunck++ < CHUNCKS)
	{
		len = stk_len(stacks[0]);
		psw_boundaries(bounds, chunck - 1, bounds[3] + 1, orig_len);
		while (len--)
		{
			if ((stacks[0] -> index >= bounds[0]) && (stacks[0] -> index <= bounds[3]))
			{
				stk_caller(stacks, "pb");
				if (stacks[1] -> index > bounds[2])
					stk_caller(stacks, "rb");
			}
			else
				stk_caller(stacks, "ra");
		}
	}
}
