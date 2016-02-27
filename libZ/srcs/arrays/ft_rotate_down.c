/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 18:30:18 by mressier          #+#    #+#             */
/*   Updated: 2016/02/06 18:30:19 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rotate_down(int *tab, size_t size)
{
	int		tmp;

	tmp = tab[size - 1];
	ft_go_down(tab, size);
	tab[0] = tmp;
}