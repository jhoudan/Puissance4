/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:33:48 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/28 11:30:31 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void		select_multiplayers(t_game *game)
{
	char	*buff;

	while (42)
	{
		ft_putstr("\033[33mEnter number of players [1 or 2]:\033[0m ");
		if (!(buff = read_one_line(0)))
			return ;
		game->multi_players = get_number(buff);
		if (game->multi_players < 1 || game->multi_players > 2)
		{
			ft_error("\033[31m[PARSE ERROR]\033[0m : ",
				buff, "\n\033[31mIs not a valid");
			ft_putendl_fd(" argument take [1 - 2]", 2);
		}
		else
		{
			ft_strdel(&buff);
			break ;
		}
		ft_strdel(&buff);
	}
}
