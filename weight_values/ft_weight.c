/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 18:45:00 by mressier          #+#    #+#             */
/*   Updated: 2016/02/28 18:45:02 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance.h"

static int		reverse_player(int player)
{
	if (player == 1)
		return (2);
	if (player == 2)
		return (1);
	return (0);
}

/*
**  	------------------------------------------------------
**  	|						MAIN	        	         |
**  	------------------------------------------------------
*/

int				ft_weight_pos(t_game *game, int column, int player)
{
	int		line;
	int		weight;

	weight = 0;
	line = get_line_pos_when_put_the_piece(*game, column);
	weight += ft_weight_player(game, player, column, line);
	weight += ft_weight_not_player(game, reverse_player(player), column, line);
	return (weight);
}

int				ft_conv(int value, int option)
{
	int		conv;

	if (option == 1)
	{
		conv = (value == 1) ? 10 : 0;
		conv = (value == 2) ? 100 : conv;
		conv = (value == 3) ? 1000 : conv;
		conv = (value >= 4) ? 100000 : conv;
	}
	if (option == 2)
	{
		conv = (value == 1) ? 45 : 0;
		conv = (value == 2) ? 190 : conv;
		conv = (value >= 3) ? 1900 : conv;
	}
	return (conv);
}
