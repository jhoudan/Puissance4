/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 13:10:37 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/28 13:11:11 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

static void	draw_border(t_game game)
{
	int x;

	x = 1;
	ft_putstr("\033[100m ");
	while (x++ < (game.column * 3))
		ft_putchar(' ');
	ft_putstr(" \033[0m\n");
}

static void	display_col(int col)
{
	int i;

	i = 0;
	while (i < col)
	{
		ft_putstr("\033[100m \033[0m");
		if (i < 10)
			ft_putchar('0');
		ft_putnbr(i);
		i++;
	}
	ft_putstr("\033[100m \033[0m");
	ft_putchar('\n');
}

static void	display_end_of_grid(t_game *game)
{
	draw_border(*game);
	display_col(game->column);
	draw_border(*game);
}

static void	draw_piece(t_game *game, int x, int y)
{
	if ((*game).grid[y / 2][x] == 1)
		ft_putstr("\033[0;41m  \033[0m");
	else if ((*game).grid[y / 2][x] == 2)
		ft_putstr("\033[0;43m  \033[0m");
	else
		ft_putstr("\033[0m  ");
	(x == (*game).column - 1) ? 0 : ft_putstr("\033[100m \033[0m");
}

void		draw_grid(t_game *game)
{
	int x;
	int y;

	y = 0;
	ft_putstr("\033[0m");
	draw_border(*game);
	while ((y++ / 2) < (*game).line)
	{
		x = 0;
		((y / 2) < (*game).line) ? ft_putstr("\033[0;100m \033[0m") : 0;
		while (x < (*game).column && y % 2 == 1)
		{
			draw_piece(game, x, y);
			++x;
		}
		while (x++ < (*game).column && y % 2 == 0 && (y / 2) < (*game).line)
		{
			ft_putstr("\033[100m  \033[0m");
			(x == (*game).column) ? 0 : ft_putstr("\033[100m \033[0m");
		}
		((y / 2) < (*game).line) ? ft_putstr("\033[100m \033[0m\n") : 0;
	}
	display_end_of_grid(game);
}
