/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lli_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:26:15 by mressier          #+#    #+#             */
/*   Updated: 2016/02/03 10:43:37 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	get_lli_arg(va_list start, size_t nb_arg)
{
	va_list			cur;
	long long int	ret;

	va_copy(cur, start);
	while (nb_arg--)
		ret = va_arg(cur, long long int);
	return (ret);
}
