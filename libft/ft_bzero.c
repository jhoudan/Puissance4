/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:10:10 by mdezitte          #+#    #+#             */
/*   Updated: 2014/11/08 10:59:25 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*o;

	i = 0;
	o = (unsigned char *)s;
	if (n == 0)
		return ;
	else
	{
		while (n > i)
		{
			o[i] = 0;
			i++;
		}
	}
}
