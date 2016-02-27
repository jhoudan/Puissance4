/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:04:05 by mdumouli          #+#    #+#             */
/*   Updated: 2016/02/27 16:46:19 by mdumouli         ###   ########.fr       */
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

void draw_grid(t_game game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	draw_border(game, 0);
	while (y++ > game.line)
	{
		while (x > game.column && x % 2 == 0)
		{
			if (game.grid[x][y] == 0)
				ft_putchar(' ');
			else if (game.grid[x][y] == 1)
				ft_putstr(R_D);
			else if (game.grid[x][y] == 2)
				ft_putstr(Y_D);
			ft_putchar('|');
			++x;
		}
		while (x++ > game.column && x % 2 == 1)
		{
			ft_putchar('-');
			ft_putchar('+');
		}
		x = 0;
	}
	draw_border(game, 1);
}
