#ifndef  FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

#include <string.h>
#include <stdio.h>

# define FT_
typedef struct s_flags
{	
	char	type;	
}	t_flags; 
void	ft_printf(char *format, ...);
void	ft_flstr(va_list args, t_flags flags);
void	ft_flchar(va_list args, t_flags flags);
#endif