/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flchars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:03:44 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/10/16 14:10:05 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

size_t	ft_flchars(char **str, va_list args, t_flags flags)
{	
	char	c;
	char	*print_str;

	if (flags.type == 'c')
	{
		c = (char)(va_arg(args, int));
		if (!c)
		{
			*str = malloc(sizeof(char) * (1));
			if (!*str)
				return (-1);
			(*str)[0] = '\0';
		}
		else
		{
			*str = malloc(sizeof(char) * (2));
			if (!*str)
				return (-1);
			(*str)[0] = c;
			(*str)[1] = '\0';
		}
	}
	else
	{
		print_str = va_arg(args, char *);
		if (!(print_str))
		{
			*str = ft_strdup("(null)");
		}
		else
		{
			*str = ft_strdup(print_str);
		}
		if (!*str)
			return (-1);
	}
	return (ft_strlen(*str));
}
