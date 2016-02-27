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

	game = init_game();
	game->column = 5;
	game->row = 4;
	game->grid = fill_grid(game->row, game->column);
	game->grid[1][2];
	ft_putnbrendl(game, 2);
	return (0);
}
