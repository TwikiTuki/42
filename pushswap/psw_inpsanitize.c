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
		psw_clean(numbers[i]);
		if (!psw_check_range(numbers[i]))	
				return (0);
		i++;
	}
	return (1);
}

void psw_clean(char *number)
{
	int i;
	int sign;

	i = 0;
	sign = 0;
	if (number[i] == '-' || number[i] == '+')
		sign = 1;
	if (sign)
		i++;
	while (number[i] == '0')
		i++;
	char *src = number + i;
	int	len = sizeof(char) * (ft_strlen(number + i) + 1);
	ft_printf("sign: %d, i: %d, src: >>%s<<, len: %d\n",sign, i , src, len);
	ft_memmove(number + sign, src, len);
	ft_printf("fasd\n");
}


int	psw_check_range(char *inp_num)
{
	int		i;
	int		len;

	len = ft_strlen(inp_num);
	if ((inp_num[0] == '-' && ft_strlen(inp_num) < 11) || (inp_num[0] != '-' && ft_strlen(inp_num) < 10))
		return (1);
	if ((inp_num[0] == '-' && ft_strlen(inp_num) > 11) || (inp_num[0] != '-' && ft_strlen(inp_num) > 10))
		return (0);
	i = 0;
	while (inp_num[i])
	{
		if (inp_num[0] == '-')
		{
			if (inp_num[i] > MIN_INT_STR[i])	
				return (0);
		}
		else
		{
			if (inp_num[i] > MAX_INT_STR[i])	
				return (0);
		}
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
	if (inp_num[i] == '0')
		return (0);
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
