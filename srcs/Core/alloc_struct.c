/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:26:28 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 13:26:30 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/puissance.h"

t_game		*init_game(void)
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	game->column = -1;
	game->line = -1;
	return (game);
}
