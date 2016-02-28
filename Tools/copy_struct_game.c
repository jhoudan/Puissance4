/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_struct_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 18:59:13 by mressier          #+#    #+#             */
/*   Updated: 2016/02/27 18:59:19 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance.h"

t_game		*copy_struct_game(t_game *original)
{
	t_game		*copy;
	int			i_line;

	i_line = 0;
	copy = init_game();
	if (copy == NULL)
		return (NULL);
	copy->column = original->column;
	copy->line = original->line;
	copy->grid = fill_grid(copy->line, copy->column);
	if (copy->grid == NULL)
		return (NULL);
	while (i_line < original->line)
	{
		copy->grid[i_line] = (int *)ft_memcpy(copy->grid[i_line],
				original->grid[i_line], copy->column * sizeof(int));
		i_line++;
	}
	return (copy);
}
