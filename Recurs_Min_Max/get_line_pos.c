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
**	Return 	
*/

int		get_line_pos(t_game grid, int column)
{
	int		line;

	line = 0;
	while (line < grid.line)
	{
		if (grid.grid[column][line] != 0)
			return (line == 0 ? -1 : line);
		line++;
	}
	return (line - 1);
}
