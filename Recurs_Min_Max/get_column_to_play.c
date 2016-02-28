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

static int			mid_is_empty(t_game *game)
{
	if (game->grid[game->line - 1][(game->column - 1) / 2] == 0)
		return (1);
	return (0);
}

static int			*get_recurs_weight_tab(t_game *game, int *values,
					int player, int depth)
{
	int		i_column;
	t_game	*cpy_game;

	i_column = 0;
	if (depth == 1)
		return (values);
	while (i_column < game->column)
	{
		if (values[i_column] != -1)
		{
			cpy_game = copy_struct_game(game);
			put_in_grid(cpy_game, i_column, player);
			values[i_column] = recurs_get_column(cpy_game, depth - 1,
				(player == 1) ? 2 : 1);
			free_game(cpy_game);
		}
		i_column++;
	}
	return (values);
}

static int			ret_value(t_game *game, int *values, int player, int depth)
{
	int		ret;

	ret = find_value_to_ret(game, values, player);
	if (depth != game->profondeur)
		ret = values[ret];
	return (ret);
}

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                            	Main                                       |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

int					recurs_get_column(t_game *game, int depth, int player)
{
	int			*values;
	int			ret;

	if (mid_is_empty(game))
		return ((game->column - 1) / 2);
	if (grid_is_full(game))
		return (0);
	ret = get_weight_pos_tab(game, &values, player);
	if (ret == -1)
		return (-1);
	ft_putnbrendl(ret);
	if (ret < WIN_VALUE && ret > -WIN_VALUE)
		values = get_recurs_weight_tab(game, values, player, depth);
	ret = ret_value(game, values, player, depth);
	ft_memdel((void **)&values);
	return (ret);
}

int					get_column_to_play(t_game *game)
{
	int				depth;
	int				ret;

	depth = game->profondeur;
	ret = recurs_get_column(game, depth, game->ia);
	return (ret);
}
