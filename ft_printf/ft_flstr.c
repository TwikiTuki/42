#include "ft_printf.h"
void ft_flstr(va_list args, t_flags flags)
{
	char	*str;
	int	ln;

	if (flags.type != 's')
		return;
	str = va_arg(args, char*);
	ln = 0;
	while(str[ln])
		ln++;
	write(1, str, ln);
}
