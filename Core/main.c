/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:15:51 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 13:23:38 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int				main(void)
{
	t_game	*game;

	game = init_game();
	take_all_param_to_begin(game);
	free_game(game);
	return (0);
}