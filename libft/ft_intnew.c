/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:44:00 by klonger           #+#    #+#             */
/*   Updated: 2016/02/18 17:34:21 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		*ft_intnew(int size, int value)
{
	int		*tab;
	int		i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		tab[i] = value;
		i++;
	}
	return (tab);
}
