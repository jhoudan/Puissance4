/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboulard <gboulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:02:40 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/17 15:00:47 by gboulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t max)
{
	size_t	i;
	size_t	a;
	char	*dest;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	a = ft_strlen(s1);
	if (a > max)
		a = max;
	dest = (char *)malloc(sizeof(char) * (a + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[i] != '\0' && i < max)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
