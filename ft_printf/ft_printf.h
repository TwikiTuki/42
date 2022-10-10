#ifndef  FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

# include <string.h>
# include <stdio.h>

char format_types[] = "cspdiuxX%";
typedef struct s_flags
{	
	char	type;	
}	t_flags; 
void ft_printf(char *format, ...);
#endif
