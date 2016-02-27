/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_is_full.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:58:44 by mressier          #+#    #+#             */
/*   Updated: 2016/02/27 19:58:45 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance.h"

int		grid_is_full(t_game *game)
{
	int		*value;
	int		i;

	i = 0;
	value = get_valid_column(*game);
	while (i < game->column)
	{
		if (value[i])
			return (0);
		i++;
	}
	return (1);
}
