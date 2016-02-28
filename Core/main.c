/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:15:51 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 19:34:17 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int				main(void)
{
	t_game	*game;

	if (!(game = init_game()))
		return (-1);
	take_all_param_to_begin(game);
	if (game->column == -1 || game->column == -1
			|| !(game->grid = fill_grid(game->line, game->column)))
	{
		free(game);
		return (-1);
	}
	if (game->game_mode == 1)
		shell_game_manager(game);
//	else if (game->game_mode == 2)
//		ncurse_game_manager(game);
	free_game(game);
	return (0);
}
