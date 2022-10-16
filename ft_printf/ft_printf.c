/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:02:50 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/10/16 15:28:10 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_getflags(const char **format);
int		ft_caller(va_list args, t_flags flags);
int		va_args_clean(va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		count;
	int		wrote;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			flags = ft_getflags(&format);
			if (flags.error)
				return (va_args_clean(args));
			wrote = ft_caller(args, flags);
		}
		else
			wrote = write(1, format, 1);
		if (wrote == -1)
			return (va_args_clean(args));
		count += wrote;
		format++;
	}
	va_end(args);
	return (count);
}

int	va_args_clean(va_list args)
{
	va_end(args);
	return (-1);
}

int	ft_caller(va_list args, t_flags flags)
{
	char	*str;	
	int		len;

	str = NULL;
	len = 0;
	if (flags.type == '%')
		return (write(1, "%", 1));
	else if (ft_strchr("c", flags.type))
		len = ft_flchar(&str, args, flags);
	else if (ft_strchr("s", flags.type))
		len = ft_flstring(&str, args, flags);
	else if (ft_strchr("pdiuxX", flags.type))
		len = ft_flnums(&str, args, flags);
	if (len == -1)
		return (-1);
	if (!str)
		return (-1);
	if (!str[0] && flags.type == 'c')
		len += 1;
	len = write(1, str, len);
	free(str);
	return (len);
}

t_flags	ft_getflags(const char **format)
{
	t_flags	result;

	(*format)++;
	while (**format && ft_strchr("cspdiuxX%", **format) == NULL)
	{
		(*format)++;
	}
	result.error = **format == '\0';
	result.type = **format;
	return (result);
}
