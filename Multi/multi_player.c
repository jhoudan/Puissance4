/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 13:15:28 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/28 13:25:54 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/puissance.h>

int			put_in_grid_and_check_if_win(t_game *game, int input, int i)
{
	if (i % 2 == 0)
	{
		put_in_grid(game, input, IA);
		if (check_if_win(game, input, IA) == 1)
		{
			draw_grid(game);
			return (ft_putendl_i("\033[34mPLAYER 1 WIN\033[0m"));
		}
	}
	else
	{
		put_in_grid(game, input, PLAYER);
		if (check_if_win(game, input, PLAYER) == 1)
		{
			draw_grid(game);
			return (ft_putendl_i("\033[34mPLAYER 2 WIN\033[0m"));
		}
	}
	return (1);
}

int			multi_player(t_game *game)
{
	int	input;
	int	max;
	int	i;

	i = -1;
	max = game->column * game->line;
	while (++i < max)
	{
		draw_grid(game);
		input = get_player_input(game);
		if (put_in_grid_and_check_if_win(game, input, i) == 0)
			return (0);
	}
	ft_putstr("\033[34mMatch nul !\033[0m\n");
	return (1);
}
