/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:58:31 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:16:26 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return a copy of s without blank at start and end of the str
*/

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t				i;
	size_t				start;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if ((start = i) == ft_strlen(s))
		return (ft_strdup(""));
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (ft_strsub(s, start, i - start + 1));
}
