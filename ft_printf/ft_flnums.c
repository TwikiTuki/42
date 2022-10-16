/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flnums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:37:45 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/10/16 15:07:21 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FT_BASE_ITOA_STR_LN 20

char	*put_prefixes(char *str, char sign, int i, t_flags fl)
{
	if (sign)
	{
		str[i] = sign;
		i--;
	}
	else if (fl.type == 'p')
	{
		str[i] = 'x';
		str[i - 1] = '0';
		i -= 2;
	}
	return (ft_strdup(str + i + 1));
}

/* i apunta al primer valor que no ha estat escrit, comencant per l'esquerra*/
char	*ft_base_itoa(long unsigned int nb, char *base, char sign, t_flags fl)
{
	char	str[FT_BASE_ITOA_STR_LN];
	int		i;
	int		nbase;

	nbase = 10;
	if (ft_strchr("pxX", fl.type))
		nbase = 16;
	i = FT_BASE_ITOA_STR_LN - 1;
	str[i] = '\0';
	i--;
	if (!nb)
		str[i--] = '0';
	while (nb)
	{
		str[i] = *(base + (nb % nbase));
		if (str[i] > '9' && fl.type == 'X')
			str[i] -= 'a' - 'A';
		nb /= nbase;
		i--;
	}
	return (put_prefixes(str, sign, i, fl));
}

long unsigned int	get_number(va_list args, char t)
{
	long unsigned int	res;

	res = 0;
	if (ft_strchr("uxX", t))
		res = (long unsigned int) va_arg(args, unsigned int);
	else if (t == 'd' || t == 'i')
		res = (long unsigned int) va_arg(args, int);
	else if (t == 'p')
		res = (long unsigned int) va_arg(args, void *);
	return (res);
}

size_t	ft_flnums(char **str, va_list args, t_flags fl)
{
	long unsigned int	number;
	char				sign;

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
