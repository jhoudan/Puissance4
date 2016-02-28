/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_game_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 11:04:46 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/28 11:04:56 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

static int	player_turn(t_game *game)
{
	int 	input;
	int		id;

	if (game->ia == 1)
		id = 2;
	else
		id = 1;
	input = get_player_input(game);
	put_in_grid(game, input, id);
	if (check_if_win(game, input, id) == 1)
	{
		draw_grid(game);
		ft_putendl("\033[34mPLAYER WIN\033[0m");
		return (1);
	}
	return (0);
}

static int	ia_turn(t_game *game)
{
	int		input;

	input = get_column_to_play(game);
	ft_putnbrendl(input);
	put_in_grid(game, input, game->ia);
	if (check_if_win(game, input, game->ia) == 1)
	{
		draw_grid(game);
		ft_putendl("\033[34mIA WIN, YOU LOOSE\033[0m");
		return (1);
	}
	return (0);
}

int		shell_game_manager(t_game *game)
{
	int i;
	int max;

	if (game->multi_players == 2)
		return (multi_player(game));
	i = -1;
	max = game->column * game->line;
	while (++i < max)
	{
		if (game->ia == 1)
		{
			if (ia_turn(game) == 1)
				return (0);
		}
		draw_grid(game);
		if (player_turn(game) == 1)
			return (2);
		if (game->ia == 2)
		{
			if (ia_turn(game) == 1)
				return (0);			
		}
	}
	ft_putstr("\033[34mMatch nul !\033[0m\n");
	return (1);
}