/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:42:27 by mressier          #+#    #+#             */
/*   Updated: 2016/02/27 15:46:39 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance.h"

int		get_line_pos(t_game grid, int column);
int		*get_valid_column(t_game game);

int		main(void)
{
	t_game	*game;	
	int		i;
	int		*ret;

	game = init_game();
	game->column = 5;
	game->line = 4;
	game->profondeur = 10;
	game->grid = fill_grid(game->line, game->column);
	game->grid[0][3] = 1;
	game->grid[0][2] = 1;
	game->grid[0][0] = 1;
	// ft_putnbrendl(get_line_pos_when_put_the_piece(*game, 3));
	game->ia = 1;
	game->profondeur = 100;
	return (0);
}
