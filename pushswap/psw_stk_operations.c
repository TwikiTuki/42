# include "push_swap.h"

void	stk_caller(t_stk_node *stacks[2], char *action)
{
	if (ft_strcmp(action, "sa"))
		stk_swap(stacks[0]);
	else if (ft_strcmp(action, "sb"))
		stk_swap(stacks[1]);
	else if (ft_strcmp(action, "ss"))
	{
		stk_swap(stacks[0]);
		stk_swap(stacks[1]);
	}
	else if (ft_strcmp(&action, "pa"))
		stk_push(stacks[0], stacks[1]);
	else if (ft_strcmp(&action, "pb"))
		stk_push(stacks[1], stacks[0]);
	else if (ft_strcmp(action, "ra"))
		stk_rotate(&stacks[0], 0);
	else if (ft_strcmp(action, "rb"))
		stk_rotate(&stacks[1], 0);
	else if (ft_strcmp(action, "rr"))
	{
		stk_rotate(&stacks[0], 0);
		stk_rotate(&stacks[1], 0);
	}
	else if (ft_strcmp(action, "rra"))
		stk_rotate(&stacks[0], 1);
	else if (ft_strcmp(action, "rrb"))
		stk_rotate(&stacks[1], 1);
	else if (ft_strcmp(action, "rrr"))
	{
		stk_rotate(&stacks[0], 1);
		stk_rotate(&stacks[1], 1);
	}
}

void stk_push(t_stk_node **stk1, t_stk_node **stk2)
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
		if ((*stk)) 
		{
			last->next = *stk;
			last->previous->next = NULL;
			last->previous = NULL;
			(*stk)->previous = last;
			*stk = last;
		}
	}
}
