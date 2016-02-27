/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:38:57 by mressier          #+#    #+#             */
/*   Updated: 2016/01/30 13:38:58 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_tolower(const char *str)
{
	char	*cur;

	cur = (char *)str;
	while (*cur)
	{
		*cur = ft_tolower(*cur);
		cur++;
	}
	return ((char *)str);
}
