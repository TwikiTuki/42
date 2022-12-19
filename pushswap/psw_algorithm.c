/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algrothm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:12:51 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/12/19 13:11:15 by jrenau-v         ###   ########.fr       */
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

static void	rotate_b(t_stk_node *stacks[], int up, int target)
{
	if (up == target)
		return ;
	if (target)
		stk_caller(stacks, "rrb");
	else
		stk_caller(stacks, "rb");
}

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
	t_stk_node		*stka;
	size_t			bounds[4];
	int				chunck;	
	int				up;
	int				target;

	chunck = 0;
	up = 0;
	bounds[3] = 0 - 1;
	while (chunck++ < CHUNCKS)
	{
		stka = stacks[0];
		psw_boundaries(bounds, chunck, bounds[3] + 1, stk_len(stacks[0]));
		//ft_printf("outer loop\n");
		while (stka)
		{
			for(int ki = 0; ki < 4; ki++) ft_printf("%d ", ki);
			ft_printf("   <<< ");stk_print(stacks[0]); ft_printf(" >>>\t\t"); ft_printf(" {%d} ", stka -> index == stacks[0] -> index);
			ft_printf("<<< ");stk_print(stacks[1]); ft_printf(" >>>  ");
			//ft_printf("inner loop: (%d, %d) next: %p  ", stka->value, stka->index, stka->next);
			if (stka -> index >= bounds[0] && stka -> index <= bounds[3])
			{
				target = stka -> index > bounds[2];
				rotate_b(stacks, up, target);
				stk_caller(stacks, "pa");
				stka = stacks[0];
				up = target;
			}
			else
				stk_caller(stacks, "ra");
			//ft_printf("end inner loop: (%d, %d) next: %p  \n", stka->value, stka->index, stka->next);
			//ft_printf("stacks[0] %p, stacks[1] %p, stka %p  \n", stacks[1],  stacks[0], stka->next);

			stka = stka -> next;
		}
	}
}
