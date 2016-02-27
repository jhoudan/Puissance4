/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:40:07 by mdezitte          #+#    #+#             */
/*   Updated: 2014/11/08 11:03:55 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*o;

	i = 0;
	o = (unsigned char*)b;
	while (i < len)
	{
		o[i] = c;
		i++;
	}
	return ((char *)b);
}
