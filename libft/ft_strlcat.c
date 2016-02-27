/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:12:17 by mdezitte          #+#    #+#             */
/*   Updated: 2016/01/04 15:37:07 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*z;
	const char	*s;
	size_t		a;
	size_t		i;

	z = dst;
	s = src;
	a = size;
	while (a-- != 0 && *z != '\0')
		z++;
	i = z - dst;
	a = size - i;
	if (a == 0)
		return (i + ft_strlen(s));
	while (*s != '\0')
	{
		if (a != 1)
		{
			*z++ = *s;
			a--;
		}
		s++;
	}
	*z = '\0';
	return (i + (s - src));
}
