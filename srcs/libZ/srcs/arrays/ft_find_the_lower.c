/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_the_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 20:08:47 by mressier          #+#    #+#             */
/*   Updated: 2016/02/11 20:08:49 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_the_lower(int *tab, size_t size)
{
	int		lower;
	int		idx;

	idx = 0;
	lower = tab[0];
	while (idx < size)
	{
		if (tab[idx] < lower)
			lower = tab[idx];
		idx++;
	}
	return (lower);
}
