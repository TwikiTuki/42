#include "ft_printf.h"
#include "./libft/libft.h"

size_t	ft_flchars(char **str, va_list args, t_flags flags)
{	
	char	c;
	char	*print_str;

	if (flags.type == 'c')
	{
		c =	(char) (va_arg(args, int));
		if (!c)
		{
			*str = malloc(sizeof(char) * (1));
			(*str)[0] = '\0';
		}
		else
		{
			*str = malloc(sizeof(char) * (2));
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
	}
	//printf("<strlen: %zu>\n", ft_strlen(*str));
	return (ft_strlen(*str));
}
