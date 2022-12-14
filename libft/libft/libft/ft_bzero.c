/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:22:24 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/29 13:22:28 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *b, size_t len)
{
	char	*cpy;

	cpy = (char *) b;
	while (len)
	{
		*cpy = 0;
		len--;
		cpy++;
	}
	return (b);
}
