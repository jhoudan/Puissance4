/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_void_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:02:30 by mressier          #+#    #+#             */
/*   Updated: 2016/01/28 14:02:33 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*get_void_arg(va_list start, size_t nb_arg)
{
	va_list	cur;
	void	*ret;

	va_copy(cur, start);
	while (nb_arg--)
		ret = va_arg(cur, void *);
	return (ret);
}
