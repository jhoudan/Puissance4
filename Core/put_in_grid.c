/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarzari <mvarzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:44:12 by mvarzari          #+#    #+#             */
/*   Updated: 2016/02/27 17:23:40 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void	put_in_grid(t_game *game, int put_in)
{
	int	line;

	line = game->line;
	line--;
	while (game->grid[line][put_in] != 0)
		line--;
	game->grid[line][put_in] = game->ia;
}
