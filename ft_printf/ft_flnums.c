/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flnums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:37:45 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/10/16 13:21:51 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long unsigned int	get_number(va_list args, char t);

char *ft_base_itoa(long unsigned int nb, char *base, char sign, t_flags fl);

size_t ft_flnums(char **str, va_list args, t_flags fl)
{
	long unsigned int number;
	char sign;

	sign = '\0';
	number = get_number(args, fl.type);
	if (ft_strchr("di", fl.type) && number >= 8000000000000000)
	{
		sign = '-';
		number = ~number + 1;
	}
	*str = ft_base_itoa(number, "0123456789abcdef", sign, fl);
	if (!*str)
		return (-1);
	return (ft_strlen(*str));
}
/* i apunta al primer valor que no ha estat escrit, comencant per l'esquerra*/
char *ft_base_itoa(long unsigned int nb,char *base, char sign, t_flags fl)
{
//					   1234567890123
	char	str[20] = "abcdefghijklm";
	int	ln = 20;
	int	i;
	char 	*result;
	int	nbase;
	
	nbase = 10;
	if (ft_strchr("pxX", fl.type))
		nbase = 16;
	i = ln - 1;
	str[i] = '\0';
	i--;
	if (!nb) //ratejar 3 linies
	{
		str[i] = '0';
		i--;
	}
	while (nb)
	{
		str[i] = *(base + (nb % nbase));
		if (str[i] > '9' && fl.type == 'X') // Ratejar 1 o 2 lines 
			str[i] -= 'a' - 'A';
		nb /=  nbase;		
		i--;
	}
	// wrap in func
	if (sign)
	{
		str[i] = sign;
		i--;
	}
	else if(fl.type == 'p')
	{
		str[i] = 'x';
		str[i-1] = '0';
		i -= 2;
	}
	// end wrap in func
	//TODO copy the string to result (ft_strdup)
	//printf("\nTemp: |%s|\n", str);
	result = ft_strdup(str + i + 1);
	return (result);
}

long unsigned int	get_number(va_list args, char t)
{
	long unsigned int res;

	res = 0;
	if (ft_strchr("uxX", t))
		res = (long unsigned int) va_arg(args, unsigned int);
	else if( t == 'd' || t == 'i')
		res = (long unsigned int) va_arg(args, int);
	else if (t == 'p')
		res = (long unsigned int) va_arg(args, void*);
	return (res);
}
