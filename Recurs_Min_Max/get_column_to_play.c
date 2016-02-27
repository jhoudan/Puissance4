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
	if (game->grid[game->line - 1][game->column / 2] == 0)
		return (1);
	return (0);
}

static int		*get_recurs_weight_tab(t_game *game, int *values, int player, int depth)
{
	int		i_column;
	t_game	*cpy_game;

	i_column = 0;
	if (depth == 1)
		return (values);
	while (i_column < game->column)
	{
		if (values[i_column])
		{
			cpy_game = copy_struct_game(game);
			put_in_grid(cpy_game, i_column);
			values[i_column] = recurs_get_column(cpy_game, depth - 1,
				(player == 1) ? 2 : 1);
			free_game(cpy_game);
		}
		i_column++;
	}
	return (values);
}

static int		ret_value(t_game *game, int *values, int player, int depth)
{
	int		ret;

	if (depth == game->profondeur)
		ret = find_value_to_ret(game, values, game->ia);
	else
	{
		ret = find_value_to_ret(game, values, player);
		ret = values[ret];
	}
	return (ret);
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
	int		*values;
	int		nb_valide_columns;
	int		i_column;
	int		ret;

	if (mid_is_empty(game))
		return (game->column / 2);
	//ret = get_weight_pos_tab(game, &values, player);
	ret = 0;
	values = ft_intnew(game->column, 1);
	if (ret == -1)
		return (-1);
	else if (ret >= WIN_VALUE)
		depth = 1;					// on considere la branche comme a la fin
	values = get_recurs_weight_tab(game, values, depth, player);
	return (ret_value(game, values, player, depth));
}

int		get_column_to_play(t_game *game)
{
	int				depth;
	int				column;

	depth = game->profondeur;
	return (recurs_get_column(game, depth, game->ia));
}
