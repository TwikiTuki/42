#include "push_swap.h"
#define combinations ((char*[]) {"012\0", "021\0", "120\0", "102\0", "201\0", "210\0"})
#define solutions ((char*[]) {"", "sa\nra\n\0", "rra\n\0", "sa\n\0", "ra\n\0", "sa\nrra\n\0"})
#define	LEN 6

void stk_strcaller(t_stk_node *stacks[], char *str)
{
	char 	action[4];
	int		i;

	i = 0;
	while (*str)
	{
		if(*str == '\n')
		{
			action[i] = '\0';
			stk_caller(stacks, action);
			i = 0;
		}
		else
		{
			action[i] = *str;
			i++;
		}
		str++;
	}
}

void stk_size3(t_stk_node *stacks[2])
{
	t_stk_node	*stka;
	char		str[4];
	int 		i;
	
	if (stk_len(stacks[0]) == 2)
	{
		if (stacks[0]->index > stacks[0]->next->index)
			stk_caller(stacks, "sa");
		return ;
	}
	stka = stacks[0];
	i = 0;
	while (stka)
	{
		str[i++] = stka->index + '0';
		stka = stka->next;
	}
	str[3] = '\0';
	i = 0;
	while (ft_strncmp(str, combinations[i], 4) && i < LEN)
	{
		i++;
	}
	stk_strcaller(stacks, solutions[i]);
}
