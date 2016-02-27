/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:38:30 by mdezitte          #+#    #+#             */
/*   Updated: 2014/11/09 18:16:12 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		a;
	char	b;

	i = 0;
	a = ft_strlen(s);
	b = (char)c;
	while (a >= i && s[a] != b)
		a--;
	if (s[a] == b)
		return ((char *)&s[a]);
	return (NULL);
}
