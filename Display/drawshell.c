/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:04:05 by mdumouli          #+#    #+#             */
/*   Updated: 2016/02/27 15:29:09 by mdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawshell.h"

void draw_border(t_game game, int nb)
{
	int x;

	x = 0;
	if (nb == 0)
	{
		ft_putchar('/');
		while (x++ < (game.column * 2))
			ft_putchar('-');
		ft_putstr("\\\n");
	}
	else
	{
		ft_putchar('\\');
		while (x++ < (game.column * 2))
			ft_putchar('-');
		ft_putstr("/\n");
	}
}
