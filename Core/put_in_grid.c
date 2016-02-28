/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarzari <mvarzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:44:12 by mvarzari          #+#    #+#             */
/*   Updated: 2016/02/27 19:42:46 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void	put_in_grid(t_game *game, int put_in, int identifier)
{
	int	line;

	line = game->line;
	line--;
	while (line < game->line && line > -1 && put_in < game->column 
		&& put_in > -1 && game->grid[line][put_in] != 0)
	{
		line--;
	}
	if (line > -1 && line < game->line && put_in < game->column && put_in > -1)
		game->grid[line][put_in] = identifier;
}
