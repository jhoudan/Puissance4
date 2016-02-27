/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_column_to_play.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 16:39:48 by mressier          #+#    #+#             */
/*   Updated: 2016/02/27 16:39:49 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance.h"

int		recurs_get_column(t_game *game, int depth, int player)

int		get_column_to_play(t_game *game)
{
	int		depth;

	depth = 3;
	return (recurs_get_column(game, depth, t_game.ia));
}
