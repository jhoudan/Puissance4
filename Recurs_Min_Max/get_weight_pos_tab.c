/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_weight_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 18:02:39 by mressier          #+#    #+#             */
/*   Updated: 2016/02/27 18:02:41 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance.h"

int		get_weight_pos_tab(t_game *game, int **values, int player)
{
	int		i_column;
	int		*valide_columns;

	i_column = 0;
	valide_columns = get_valid_column(*game);
	*values = ft_intnew(game->column, -1);
	if (*values == NULL)
		return (-1);
	while (i_column < game->column)
	{
		if (valide_columns[i_column])
			(*values)[i_column] = ft_weight_pos(game, i_column, player);
		if ((*values)[i_column] >= WIN_VALUE)
		{
			(*values)[i_column] = ((player == game->ia) ?
				(*values)[i_column] : -(*values)[i_column]);
			return ((*values)[i_column]);
		}
		i_column++;
	}
	ft_memdel((void **)&valide_columns);
	return (1);
}
