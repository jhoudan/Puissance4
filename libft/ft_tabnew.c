/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:54:23 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/26 18:24:52 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabnew(size_t len)
{
	char	**ret;
	size_t	i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		ret[i] = NULL;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
