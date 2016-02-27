/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:04:05 by mdumouli          #+#    #+#             */
/*   Updated: 2016/02/27 19:46:03 by mdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void draw_border(t_game game)
{
	int x;

	x = 1;
	ft_putstr("\e[100m ");
	while (x++ < (game.column * 2))
		ft_putchar(' ');
	ft_putstr(" \e[0m\n");
}

void draw_grid(t_game *game)
{
	int x;
	int y;

	y = 0;
	ft_putstr("\e[0m");
	draw_border(*game);
	while ((y++ / 2) < (*game).line)
	{
		x = 0;
		((y / 2) < (*game).line) ? ft_putstr("\e[0;100m \e[0m") : 0;
		while (x < (*game).column && y % 2 == 1)
		{
			if ((*game).grid[y / 2][x] == 1)
				ft_putstr(RED_DOT);
			else if ((*game).grid[y / 2][x] == 2)
				ft_putstr(YELLOW_DOT);
			else
				ft_putstr("\e[0m ");
			(x == (*game).column - 1) ? 0 : ft_putstr("\e[100m \e[0m");
			++x;
		}
		while (x++ < (*game).column && y % 2 == 0 && (y / 2) < (*game).line)
		{
			ft_putstr("\e[100m \e[0m");
			(x == (*game).column) ? 0 : ft_putstr("\e[100m \e[0m");
			}
		((y / 2) < (*game).line) ? ft_putstr("\e[100m \e[0m\n") : 0;
	}
	draw_border(*game);
}
