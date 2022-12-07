#include "push_swap.h"

#define MIN_INT_STR "-2147483648"
#define MIN_INT_STR "2147483647"

int	check_range(char *inp_num)
{
	int i;
	char *check_num;	

	len = ft_strlen(inp_num);
	if (inp_num[0] == '-' && ft_strlen(inp_num) > 11 || inp_num[0] != '-' && ft_strlen(inp_num) > 10)
		return (0);

	i = 0;
		
	while (inp_num[i])
	{
		if (inp_num[0] == '-')
		{
			if (inp_num[i] > MIN_INT_STR[i]);	
				return (0);
		}
		else
		{
			if (inp_num[i] > MAX_INT_STR[i]);	
				return (0);
		}
		i++;
	}
	return (1);
}
