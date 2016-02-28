/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 18:43:46 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/28 18:43:56 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

static int	put_mouse_value(int column, t_game *game, int id)
{
	int		row;
	int		col;

	getmaxyx(stdscr, row, col);
	col = col > 222 ? 222 : col;
	if (column % (col / game->column) != 0)
	{
		if (column > (col / game->column))
			put_in_grid(game, column / (col / game->column), id);
		else
			put_in_grid(game, 0, id);
		put_vals(game);
		return (column / (col / game->column));
	}
	return (-1);
}

void		check_scr_size(t_game *game)
{
	int		row;
	int		col;

	getmaxyx(stdscr, row, col);
	if (((game->line * 4) + 1) > row || ((game->column * 6) + 1) > col)
	{
		clear();
		mvaddstr(0, 0, "Window too small, please make it bigger to continue");
		refresh();
	}
	else
		draw_grid_ncurses(game);
}

int			key_manager(int key, t_game *game)
{
	int		input;
	int		id;
	MEVENT	event;

	id = game->ia == 1 ? 2 : 1;
	if (key == KEY_RESIZE)
	{
		check_scr_size(game);
		return (3);
	}
	if (key == KEY_MOUSE)
	{
		assert(getmouse(&event) == OK);
		if (event.bstate == 4)
		{
			input = put_mouse_value(event.x, game, id);
			if (input == -1)
				return (3);
			if (check_if_win(game, input, id) == 1)
				return (1);
		}
	}
	return (0);
}
