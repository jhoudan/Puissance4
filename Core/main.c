/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:15:51 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 14:28:03 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int				main(void)
{
	t_game	*game;
	int		input;

	game = init_game();
	take_all_param_to_begin(game);
	if (!(game->grid = fill_grid(game->line, game->column)))
	{
		free(game);
		return (-1);
	}
	input = get_player_input(game);
	free_game(game);
	return (0);
}
