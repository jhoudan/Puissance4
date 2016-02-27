/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:15:51 by mdezitte          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int				main(void)
{
	t_game	*game;
	int		input;

	if (!(game = init_game()))
		return (-1);
	take_all_param_to_begin(game);
	if (game->column == -1 || game->column == -1
			|| !(game->grid = fill_grid(game->line, game->column)))
	{
		free(game);
		return (-1);
	}
	// ncurses_init(game);
	input = get_player_input(game);
	draw_grid(game);
	if (game->multi_players == 1)
	{
	}
	else
		multi_player(game);
	free_game(game);
	return (0);
}
