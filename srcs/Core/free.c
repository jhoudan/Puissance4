/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:25:46 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 13:57:18 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/puissance.h"

void		free_game(t_game *game)
{
	delete_grid(game->grid, grid->line);
	free(game);
	game = NULL;
}
