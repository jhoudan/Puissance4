/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:04:05 by mdumouli          #+#    #+#             */
/*   Updated: 2016/02/27 18:57:40 by mdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void draw_border(t_game game, int nb)
{
	int x;

	x = 1;
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

void draw_grid(t_game *game)
{
	int x;
	int y;

	y = 0;
	ft_putstr("\e[0m");
	draw_border(*game, 0);
	while ((y++ / 2) < (*game).line)
	{
		x = 0;
		((y / 2) < (*game).line) ? ft_putchar('|') : 0;
		while (x < (*game).column && y % 2 == 1)
		{
			if ((*game).grid[y / 2][x] == 1)
				ft_putstr(RED_DOT);
			else if ((*game).grid[y / 2][x] == 2)
				ft_putstr(YELLOW_DOT);
			else
				ft_putchar (' ');
			(x == (*game).column - 1) ? 0 : ft_putchar('|');
			++x;
		}
		while (x++ < (*game).column && y % 2 == 0 && (y / 2) < (*game).line)
		{
			ft_putchar('-');
			(x == (*game).column) ? 0 : ft_putchar('+');
			}
		((y / 2) < (*game).line) ? ft_putstr("|\n") : 0;
	}
	draw_border(*game, 1);
}
