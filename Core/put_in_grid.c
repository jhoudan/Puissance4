/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarzari <mvarzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:44:12 by mvarzari          #+#    #+#             */
/*   Updated: 2016/02/27 15:14:03 by mvarzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void	put_in_grid(t_game *game, int put_in)
{
	int	lines;

	lines = game->line;
	lines--;
	while (game->grid[lines][put_in] != 0)
	   lines--;
	game->grid[lines][put_in] = game->ia;	
}
