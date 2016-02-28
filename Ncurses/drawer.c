/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 18:43:26 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/28 18:43:41 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

static void	put_circle(int x, int y, int identifier)
{
	wattron(stdscr, COLOR_PAIR(identifier));
	mvaddstr(x - 1, y - 2, " /|\\ ");
	mvaddstr(x, y - 2, "|||||");
	mvaddstr(x + 1, y - 2, " \\|/ ");
	wattroff(stdscr, COLOR_PAIR(identifier));
}

static int	*createtab(int xa, int ya, int xb, int yb)
{
	int			*tab;

	tab = (int *)malloc(sizeof(int) * 4);
	tab[0] = xa;
	tab[1] = ya;
	tab[2] = xb;
	tab[3] = yb;
	return (tab);
}

static void	drawline(int *t, char ch)
{
	int i;

	init_color(COLOR_WHITE, 500, 500, 500);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	wattron(stdscr, COLOR_PAIR(3));
	i = 0;
	if (t[0] == t[2])
	{
		while (t[1] + i < t[3])
		{
			mvaddch(t[0], t[1] + i, ch);
			i++;
		}
	}
	else
	{
		while (t[0] + i < t[2])
		{
			mvaddch(t[0] + i, t[1], ch);
			i++;
		}
	}
	wattroff(stdscr, COLOR_PAIR(3));
	free(t);
}

void		put_vals(t_game *game)
{
	int	x;
	int	y;
	int row;
	int col;

	getmaxyx(stdscr, row, col);
	col = col > 222 ? 222 : col;
	x = game->line;
	while (x > 0)
	{
		y = game->column;
		while (y > 0)
		{
			if (game->grid[x - 1][y - 1] != 0)
				put_circle(((row / game->line) * x + (row / game->line) *
					(x - 1)) / 2, ((col / game->column) * y +
						(col / game->column) * (y - 1)) / 2,
							game->grid[x - 1][y - 1]);
			y--;
		}
		x--;
	}
}

void		draw_grid_ncurses(t_game *game)
{
	int row;
	int col;
	int x;
	int i;

	clear();
	start_color();
	getmaxyx(stdscr, row, col);
	col = col > 222 ? 222 : col;
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	x = 0;
	while (x <= game->column)
	{
		i = (col / game->column) * x++;
		drawline(createtab(0, i, (row / game->line) * game->line + 1, i), ' ');
	}
	x = 0;
	while (x <= game->line)
	{
		i = (row / game->line) * x++;
		drawline(createtab(i, 0, i, (col / game->column) * game->column), ' ');
	}
	put_vals(game);
	refresh();
}
