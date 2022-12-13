#include "push_swap.h"

#define MAX_INT_STR "2147483647"
#define MIN_INT_STR "-2147483648"

int	psw_check(char **numbers)
{
	size_t	i;

	i = 0;
	while (numbers[i])
	{
		if (!psw_check_general(numbers[i]))	
				return (0);
		if (!psw_check_range(numbers[i]))	
				return (0);
		i++;
	}
	return (1);
}

static int	psw_find_start(char *inp_num)
{
	int start;
	
	start = 0;
	if (inp_num[start++] == '-')
		start++;
	while (inp_num[start++] == '0')
		start++;
	return (start);
}

int	psw_check_range(char *inp_num)
{
	int		i;
	int		len;
	int		start;

	len = ft_strlen(inp_num);
	start = psw_find_start(inp_num);
	len = len - start;
	ft_printf("len: %d, start: %d, finalLen: %d\n", len, start, len - start);
	if ((inp_num[0] == '-' && len < 10) || (inp_num[0] != '-' && len < 10))
		return (1);
	if ((inp_num[0] == '-' && len > 10) || (inp_num[0] != '-' && len > 10))
		return (0);
	ft_printf("len ok\n");
	i = 0;
	while (inp_num[i])
	{
		if (inp_num[0] == '-')
		{
			if (inp_num[i + start] > MIN_INT_STR[i + 1])	
				return (0);
		}
		else if (inp_num[i + start] > MAX_INT_STR[i])	
				return (0);
		i++;
	}
	return (1);
}

int	psw_check_general(char *inp_num)
{
	int i;

	i = 0;
	if (inp_num[i] == '-' || inp_num[i] == '+')
		i++;
	while (inp_num[i])
	{
		if (inp_num[i] < '0'  || inp_num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int psw_getindexes(t_stk_node *start)
{
	t_stk_node	*to_sort;
	t_stk_node	*to_cmpr;		
	
	to_sort = start;
	while (to_sort)
	{
		to_sort -> index = 0;
		to_cmpr = start; 
		while (start)
		{
			if (to_sort -> value >  to_cmpr -> value)
				to_sort -> index += 1;
			if (to_sort -> value == to_cmpr -> value && to_sort != to_cmpr) 
				return (0);
		}
	}
	return (1);
}
