/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 18:44:00 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/28 18:44:02 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

static int	ia_turn_ncurse(t_game *game)
{
	int		input;

	input = get_column_to_play(game);
	put_in_grid(game, input, game->ia);
	if (check_if_win(game, input, game->ia) == 1)
		return (2);
	put_vals(game);
	return (0);
}

static void	multiplayer_ncurses(t_game *game)
{
	int max;
	int ch;
	int i;
	int win;

	i = -1;
	max = game->column * game->line;
	while ((ch = getch()) != 27 && ++i < max)
	{
		if (game->ia == 1 && win != 3)
			game->ia = 2;
		else if (game->ia == 2 && win != 3)
			game->ia = 1;
		win = key_manager(ch, game);
		if (win == 1)
			break ;
		put_vals(game);
	}
	endwin();
	draw_grid(game);
}

static void	game_ncurses(t_game *game, int max, int i)
{
	int ch;
	int win;

	if (game->multi_players == 2)
	{
		multiplayer_ncurses(game);
		return ;
	}
	if (game->ia == 1)
		ia_turn_ncurse(game);
	while ((ch = getch()) != 27 && ++i < max)
	{
		win = key_manager(ch, game);
		put_vals(game);
		if (win == 1)
			break ;
		if (win != 3)
		{
			if (ia_turn_ncurse(game) == 2)
			{
				win = 2;
				break ;
			}
		}
	}
}

void		ncurses_init(t_game *game)
{
	int max;

	max = game->column * game->line;
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	check_scr_size(game);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	game_ncurses(game, max, -1);
	endwin();
	draw_grid(game);
}
