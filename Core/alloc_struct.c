/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:26:28 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 14:38:03 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

t_game		*init_game(void)
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	game->column = -1;
	game->line = -1;
	return (game);
}

int			**fill_grid(int line, int column)
{
	int	**grid;
	int	i;

	grid = (int**)malloc(sizeof(int*) * (line + 1));
	if (!grid)
		return (NULL);
	grid[line] = NULL;
	while (--line >= 0)
	{
		grid[line] = (int*)malloc(sizeof(int) * column);
		if (!grid[line])
			return (NULL);
		i = 0;
		while (i < column)
		{
			grid[line][i] = 0;
			i++;
		}
	}
	return (grid);
}
