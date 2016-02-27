/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 14:50:06 by mdezitte          #+#    #+#             */
/*   Updated: 2015/12/14 16:27:42 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_strdel_2d(char ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i])
	{
		ft_strdel(&(*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}
