/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:25:46 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 14:37:55 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

static int	delete_grid(int **grid, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(grid[i]);
		grid[i] = NULL;
		i++;
	}
	free(grid);
	grid = NULL;
	return (1);
}

void		free_game(t_game *game)
{
	delete_grid(game->grid, game->line);
	free(game);
	game = NULL;
}
