/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_player_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 21:05:05 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 21:05:14 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int		check_bot_left(t_game *game, int out, int line, int id)
{
	int i;
	int	nb_piece;

	i = 1;
	nb_piece = 1;
	while (out + i < game->column && game->grid[line - i][out + i] == id)
		i++;
	nb_piece += i - 1;
	i = 1;
	while (out - i >= 0 && game->grid[line + i][out - i] == id)
		i++;
	nb_piece += i - 1;
	return (nb_piece);
}

int		check_bot_right(t_game *game, int out, int line, int id)
{
	int i;
	int	nb_piece;

	i = 1;
	nb_piece = 1;
	while (out + i < game->column && game->grid[line - i][out - i] == id)
		i++;
	nb_piece += i - 1;
	i = 1;
	while (out - i >= 0 && game->grid[line + i][out + i] == id)
		i++;
	nb_piece += i - 1;
	return (nb_piece);
}
