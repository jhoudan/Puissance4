/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:25:46 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 13:58:37 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/puissance.h"

void		free_game(t_game *game)
{
	delete_grid(game->grid, game->line);
	free(game);
	game = NULL;
}