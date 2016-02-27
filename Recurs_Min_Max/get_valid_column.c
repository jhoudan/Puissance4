/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_column.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 16:16:12 by mressier          #+#    #+#             */
/*   Updated: 2016/02/27 16:16:15 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance.h"

/*
**	Renvoie un tableau d'int.
**	Chaque case correspond a une colonne.
**	Si la case de ret est a 0, la ligne est pleine, on ne peut plus rien
**	mettre dedans.
*/

int		*get_valid_column(t_game game)
{
	int		*ret;
	int		i_column;

	ret = (int *)ft_memalloc(sizeof(int) * game.column);
	if (ret == NULL)
		return (NULL);
	i_column = 0;
	while (i_column < game.column)
	{
		if (game.grid[0][i_column] == 0)
			ret[i_column] = 1;
		i_column++;
	}
	return (ret);
}
