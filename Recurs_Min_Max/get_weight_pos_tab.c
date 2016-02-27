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

int		get_weight_pos_tab(t_game *game, int **weight_pos_tab, int player)
{
	int		i_column;
	int		*valide_columns;

	i_column = 0;
	valide_columns = get_valid_column(*game);
	*weight_pos_tab = ft_intnew(game->column, -1);
	if (*weight_pos_tab == NULL)
		return (-1);
	while (i_column < game->column)
	{
		//if (valide_columns[i_column])
		//	*weight_pos_tab[i_column] = ft_weight_pos(game, i_column, player);
		if (*weight_pos_tab[i_column] >= WIN_VALUE)
			return (*weight_pos_tab[i_column]);
		i_column++;
	}
	return (1);
}
