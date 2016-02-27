/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:38:34 by mressier          #+#    #+#             */
/*   Updated: 2016/01/30 13:38:35 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(const char *str)
{
	char	*cur;

	cur = (char *)str;
	while (*cur)
	{
		*cur = ft_toupper(*cur);
		cur++;
	}
	return ((char *)str);
}
