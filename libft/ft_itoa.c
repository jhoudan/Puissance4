/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reya <reya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 11:43:40 by mdezitte          #+#    #+#             */
/*   Updated: 2015/12/12 20:27:13 by reya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>

static char	*ft_fuck_vingt_cinq_line(char *s, int n, int sign, size_t i)
{
	s[i--] = '\0';
	if (n == INT_MIN)
		s[i--] = 56;
	else
		s[i--] = (sign * n % 10) + 48;
	while ((n = n / 10))
	{
		s[i] = (sign * n % 10) + 48;
		i--;
	}
	if (sign == -1)
		s[i] = '-';
	return (s);
}

char		*ft_itoa(int n)
{
	size_t	i;
	int		n_;
	int		sign;
	char	*s;

	i = 1;
	n_ = n;
	sign = 1;
	if (n < 0)
		sign = -1;
	while (n / 10)
	{
		i++;
		n = n / 10;
	}
	if (sign == -1)
		i++;
	s = (char *)malloc(sizeof(s) * (i + 1));
	if (!s)
		return (NULL);
	n = n_;
	s = ft_fuck_vingt_cinq_line(s, n, sign, i);
	return (s);
}
