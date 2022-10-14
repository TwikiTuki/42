#include "ft_printf.h"

t_flags ft_getflags(const char **format);
int		ft_caller(va_list args, t_flags flags);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		count;
	int		wrote;
	
	va_start(args, format);
	count = 0;
	while(*format)
	{
		if (*format == '%')
		{
			flags = ft_getflags(&format);
			if (flags.error)
			{
				va_end(args);
				return (-1);
			}
			wrote = ft_caller(args, flags);	
		}
		else // reatear linias
		{
			wrote = write(1, format, 1);
		}	
		if (wrote == -1)
		{
			va_end(args);
			return (-1);
		}
		count += wrote;
		if(*format)
			format++;
	}
	va_end(args);
	return (count);
}

int	ft_caller(va_list args, t_flags flags)
{
	char	*str;	
	size_t	len;

	str = NULL;
	len = 0;
	if (flags.type == '%')
		return (write(1, "%", 1));	
	else if (ft_strchr("cs", flags.type))
		len = ft_flchars(&str, args, flags);
	else if (ft_strchr("pdiuxX", flags.type))
		len = ft_flnums(&str, args, flags);
	if (!len && flags.type == 'c') // if the character is \0 returns a 0 len string
		len = 1;
	if (!str)
		return (-1);
	//TODO add padding
	write(1, str, len);
	//TODO add back-padding
	/*
	if (str)
		free(str);
	*/
	free(str);
	return (len);
}

t_flags ft_getflags(const char **format)
{
	t_flags	result;
	
	(*format)++;
	while (**format && ft_strchr("cspdiuxX%", **format) == NULL)
	{
		(*format)++;
	}
	result.error = **format == '\0';
	result.type = **format;
	//printf("|result type: %c|\n", result.type);
	return (result);
} 
