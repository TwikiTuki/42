#include "ft_printf.h"

long unsigned int	get_number(va_list args, char t);

size_t ft_flnums(char **str, va_list args, t_flags fl)
{
	long unsigned int number;
	char sign;
	int	nbase;

	sign = '\0';
	number = get_number(args, fl.type);
	if (FT_ strchrs("di", fl.type) && number >= 8000000000000000)
	{
		sign = '-';
		number = ~number + 1;
	}
	*str = ft_base_itoa(number, "0123456789abcdef", sign, fl)
}

char *ft_base_itoa(long unsigned int nb,
	base, char sign, t_flabs fl)
{
	char	str[13];
	int	ln = 13;
	int	i;
	char 	*result;
	int	nbase;
	
	nbase = 10;
	if (FT_ strchr("pxX", fl.type))
		nbase = 16;
	i = ln - 1;
	str[i]  '\0';
	str[i - 1]  '0';
	while (nb)
	{
		str[i] = base[nb / base];
		nb /=  nbase;		
		i--;
	}
	// wrap in func
	if (sing)
		str[i] = sign;
	else if(fl.type = 'p')
	{
		str[i] = 'x';
		i--;
		str[i] = '0';
	}
	i--;
	// end wrap in func
	result = malloc(sizeof(char) * (ln - i))
	if (!result)
		return (NULL);
	//TODO copy the string to result (ft_strdup)
}

	
}

long unsigned int	get_number(va_list args, char t)
{
	long unsigned int res;

	if (FT_ strchrs("uxX"), t)
		res = (long unsigned int) va_arg(args, unsigned int);
	else if( c == 'd' || c == 'i')
		res = (long unsigned int) va_arg(args, int);
	else if (c == 'p')
		res = (long unsigned int) va_arg(args, void* );
	return (res);
}
