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

static int		get_the_one_nearest_to_mid(int index_1, int index_2, int mid)
{
	int		res1;
	int		res2;

	res1 = mid - index_1;
	res2 = mid - index_2;
	if (res1 < 0)
		res1 = -res1;
	if (res2 < 0)
		res2 = -res2;
	if (res1 < res2)
		return (index_1);
	else if (res2 < res1)
		return (index_2);
	else
	{
		srand(time(NULL));
		if ((rand() % 2) + 1 == 1)
			return (index_1);
		else
			return (index_2);
	}
}

static int		get_the_most_little(t_game *game, int *values)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (i < game->column)
	{
		if (values[ret] == -1
				|| (values[i] < values[ret] && values[i] != -1))
			ret = i;
		if (values[i] == values[ret])
			ret = get_the_one_nearest_to_mid(i, ret,
				(game->column - 1) / 2);
		i++;
	}
	return (ret);
}

static int		get_the_higher(t_game *game, int *values)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < game->column)
	{
		if (values[i] > values[ret])
			ret = i;
		if (values[i] == values[ret])
			ret = get_the_one_nearest_to_mid(i, ret,
				(game->column - 1) / 2);
		i++;
	}
	return (ret);
}

/*
** |----------------------------------------------------------------------------
** |                                 Main                                      |
** |----------------------------------------------------------------------------
*/

int				find_value_to_ret(t_game *game, int *values, int player)
{
	int		ret;

	if (player == game->ia)
		ret = get_the_higher(game, values);
	else
		ret = get_the_most_little(game, values);
	return (ret);
}
