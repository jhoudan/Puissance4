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

static int		mid_is_empty(t_game *game)
{
	if (game->grid[grid->line - 1][grid->column / 2] == 0)
		return (1);
	return (0);
}

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                            	Main                                       |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

int				recurs_get_column(t_game *game, int depth, int player)
{
	int		*columns;
	int		nb_valide_columns;
	int		i_column;
	int		ret;

	if (mid_is_empty(game))
		return (game->column / 2);
	else
	{
		nb_valide_columns = get_nb_valide_columns(game);
		ret = get_weight_pos_tab(game, &columns, nb_valide_columns);
		
	}
}

int		get_column_to_play(t_game *game)
{
	int				depth;
	int				column;
	t_value_pos

	depth = game->profondeur;
	
	return (recurs_get_column(game, depth, t_game.ia));
}
