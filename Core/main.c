/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:15:51 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 14:25:27 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int				main(void)
{
	t_game	*game;
	int		input;

	game = init_game();
	take_all_param_to_begin(game);
	game->grid = fill_grid(game->line, game->column);
	input = get_player_input(game);
	free_game(game);
	return (0);
}
