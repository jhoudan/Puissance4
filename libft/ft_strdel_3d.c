/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 14:50:13 by mdezitte          #+#    #+#             */
/*   Updated: 2015/12/14 17:43:51 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strdel_3d(char ****tab)
{
	int i;
	int y;

	i = 0;
	while ((*tab)[i])
	{
		y = 0;
		while ((*tab)[i][y])
		{
			free((*tab)[i][y]);
			(*tab)[i][y] = NULL;
			y++;
		}
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}
