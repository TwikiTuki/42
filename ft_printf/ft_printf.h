/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:30:19 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/10/16 15:31:59 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_flags
{	
	char	type;	
	int		error;
}	t_flags;
int		ft_printf(const char *format, ...);
void	ft_flstr(va_list args, t_flags flags);
int		ft_flchar(char **str, va_list args, t_flags flags);
int		ft_flstring(char **str, va_list args, t_flags flags);
size_t	ft_flnums(char **str, va_list args, t_flags flags);
#endif
