#include "ft_printf.h"

t_flags ft_getflags(char **format);
void	ft_caller(va_list args, t_flags flags);
void ft_printf(char *format, ...)
{
	va_list	args;
	t_flags	flags;
	va_start(args, format);
	while(*format)
	{
		if (*format == '%')
		{
			flags = ft_getflags(&format);
			ft_caller(args, flags);	
		}
		else
		{
			write(1, format, 1); 
		}	
		if(*format)
			format++;
	}
	va_end(args);
}

void	ft_caller(va_list args, t_flags flags)
{
	if(flags.type == '%')
		write(1, "%", 1);	
	else if(flags.type == 'c'
		ft_flchar(args, flags);
	else if(flags.type == 's')
	{
		ft_flstr(args, flags);
	}
	return ;
}

t_flags ft_getflags(char **format)
{
	t_flags	result;
	
	(*format)++;
	while (**format && FT_ strchr("cspdiuxX%", **format) == NULL)
	{
		(*format)++;
	}
	result.type = **format;
	//printf("|result type: %c|\n", result.type);
	return (result);
} 

