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
			printf("FLAGS POINTER: %p\n", &flags); 	
			
			//call function
		}
		else
		{
			write(1, format, 1); 
			format++;
		}	
	}
	va_end(args);
}

void	ft_caller(va_list args, t_flags flags)
{
	printf("%p%p",&args, &flags);
	return ;
}

t_flags ft_getflags(char **format)
{
	t_flags	result;

	while (**format && !strchr(format_types, **format))
	{
		(*format)++;
	}
	result.type = **format;
	(*format)++;
	printf("result type: %c\n", result.type);
	return (result);
} 

