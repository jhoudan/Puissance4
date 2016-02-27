/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_str_in_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:03:02 by mdezitte          #+#    #+#             */
/*   Updated: 2016/01/30 17:50:05 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_str_in_str(const char *line, const char *insert, int index)
{
	char	*dst;
	int		y;
	int		i;
	int		w;

	i = 0;
	dst = ft_strnew(ft_strlen(line) + ft_strlen(insert) + 1);
	while (i < index - 1 && line[i] != '\0')
	{
		dst[i] = line[i];
		i++;
	}
	y = 0;
	w = i;
	while (insert[y])
	{
		dst[i] = insert[y];
		i++;
		y++;
	}
	while (line[w])
		dst[i++] = line[w++];
	return (dst);
}
