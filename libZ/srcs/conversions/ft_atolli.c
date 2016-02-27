/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:43:16 by mressier          #+#    #+#             */
/*   Updated: 2016/02/04 13:59:01 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Convert a str into an int
*/

#include "libft.h"

long long int			ft_atolli(const char *nptr)
{
	unsigned long long int	n;

	n = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if ((*nptr == '-' && ft_isdigit(*(nptr + 1))) ||
		(*nptr == '+' && ft_isdigit(*(nptr + 1))))
		return ((*nptr == '-') ? -(ft_atolli(++nptr)) : ft_atolli(++nptr));
	while (ft_isdigit(*nptr))
		n = n * 10 + *nptr++ - 48;
	return (n);
}
