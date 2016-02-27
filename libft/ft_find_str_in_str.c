/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_str_in_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:38:29 by mdezitte          #+#    #+#             */
/*   Updated: 2016/01/30 17:54:28 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char		*ft_find_str_in_str(const char *source, const char *arg)
{
	int			src;
	int			ar;
	int			tm;
	const char	*tmp;

	src = 0;
	ar = 0;
	tm = 0;
	while (source[src])
	{
		if (source[src] == arg[ar])
		{
			tmp = &source[src];
			tm = src;
			while (source[src++] == arg[ar++])
			{
				if (ar >= (int)ft_strlen(arg))
					return (tmp);
			}
			src = tm;
			ar = 0;
		}
		src++;
	}
	return (NULL);
}
