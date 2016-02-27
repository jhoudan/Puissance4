/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:04:05 by mdumouli          #+#    #+#             */
/*   Updated: 2016/02/27 15:16:12 by mdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawshell.h"

void draw_border(t_grid grid, int nb)
{
	int x;

	x = 0;
	if (nb == 0)
	{
		ft_putchar('/');
		while (x++ < (grid.lengh * 2))
			ft_putchar('-');
		ft_putstr("\\\n");
	}
	else
	{
		ft_putchar('\\');
		while (x++ < (grid.lengh * 2))
			ft_putchar('-');
		ft_putstr("/\n");
	}
}
