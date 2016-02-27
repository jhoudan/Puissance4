/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:26:28 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 14:13:32 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/puissance.h"

t_game		*init_game(void)
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	game->column = -1;
	game->line = -1;
	game->grid = NULL;
	return (game);
}

int		**fill_grid(int row, int column)
{
	int	**grid;
	int	i;

	grid = (int**)malloc(sizeof(int*) * row + 1);
	if (!grid)
		return (NULL);
	grid[row] = NULL;
	while (--row >= 0)
	{
		grid[row] = (int*)malloc(sizeof(int) * column);
		if (!grid[row])
			return (NULL);
		i = 0;
		while (i < column)
		{
			grid[row][i] = 0;
			i++;
		}
	}
	return (grid);
}

int		delete_grid(int **grid, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return (1);
}
