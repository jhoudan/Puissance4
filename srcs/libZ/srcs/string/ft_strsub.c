/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:58:22 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:15:26 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Return a str of the piece of s (since s[start] with a lenght of len)
*/

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*new_s;

	if (!s)
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s);
	new_s = ft_strnew(len);
	new_s = ft_strncpy(new_s, &(s[start]), len);
	return (new_s);
}
