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

int		main(void)
{
	t_game	*game;	
	int		i;
	int		*ret;

	game = init_game();
	game->column = 4;
	game->line = 4;
	game->grid = fill_grid(game->line, game->column);
	game->grid[3][1] = 2;
	game->grid[3][0] = 2;
	// game->grid[2][1] = 1;
	// game->grid[3][0] = 2;
	// game->grid[2][0] = 1;
	// ft_putnbrendl(get_line_pos_when_put_the_piece(*game, 3));
	game->ia = 1;
	game->profondeur = 3;
	i = get_column_to_play(game);
	ft_putstr("Ret = ");
	ft_putnbrendl(i);
	return (0);
}
