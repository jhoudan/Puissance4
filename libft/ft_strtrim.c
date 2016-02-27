/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 23:07:08 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/01 17:57:32 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*dst;
	int		i;
	int		d;

	i = 0;
	d = 0;
	if (!s || !s[i])
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	dst = (char *)malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (dst == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dst[d] = s[i];
		d++;
		i++;
	}
	dst[d] = '\0';
	d--;
	while (d >= 0 && (dst[d] == ' ' || dst[d] == '\n' || dst[d] == '\t'))
		d--;
	dst[d + 1] = '\0';
	return (dst);
}
