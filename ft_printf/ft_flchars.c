#include "ft_printf.h"

size_t	ft_flchar(char **str, va_list args, t_flags flags)
{	
	if (flags.type == 'c')
	{
		*str = malloc(sizeof(char) * (2));
		*str[0] = va_arg(args, int);
		*str[1] = '\0';
	}
	else
	{
		// this is wrong as fuck *str will be freed in ft_caller
		// this should use strdup
		*str = va_arg(args, char*);
	}
	return (FT_ strlen(*str));
}
