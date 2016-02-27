/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value_to_ret.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:08:09 by mressier          #+#    #+#             */
/*   Updated: 2016/02/27 19:08:10 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance.h"

int		find_value_to_ret(t_game *game, int *values, int player)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (player == game->ia)
	{
		while (i < game->column)
		{
			if (values[i] > values[ret])
				ret = i;
			i++;
		}
	}
	else
	{
		while (i < game->column)
		{
			if (values[i] < values[ret])
				ret = i;
			i++;
		}
	}
	return (ret);
}
