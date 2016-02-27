/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:20:28 by mdezitte          #+#    #+#             */
/*   Updated: 2014/11/21 12:25:58 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tion;
	char	*rce;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	tion = (char *)dst;
	rce = (char *)src;
	while (i < (n - 1))
	{
		tion[i] = rce[i];
		i++;
	}
	tion[i] = rce[i];
	return (dst);
}
