/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:28:11 by mressier          #+#    #+#             */
/*   Updated: 2016/02/27 15:28:12 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance.h"

/*
**	Renvoie la position littérale de l'endroit ou la piece va se poser
**	dans la colonne. -1 si la colonne est pleine ou en cas d'erreur (ce que je
**	ne souhaite pas)
*/

int		get_line_pos(t_game game, int column)
{
	int		line;

	line = 0;
	if (column < 0 || column > game.column)
		return (-1);
	while (line < game.line)
	{
		if (game.grid[line][column] != 0)
			return (line == 0 ? -1 : line - 1);
		line++;
	}
	return (line - 1);
}
