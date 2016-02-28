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

void		take_profondeur(t_game *game, int values)
{
	int		nb_case;

	nb_case = game->column * game->line;
	if (values == 0)
		game->profondeur = (nb_case > 1000) ? 1 : 3;
	if (values == 1)
	{
		if (nb_case > 1000)
			game->profondeur = 1;
		else if (nb_case > 225)
			game->profondeur = 3;
		else
			game->profondeur = 5;
	}
	if (values == 2)
	{
		if (nb_case > 200)
			game->profondeur = 3;
		else if (nb_case > 50)
			game->profondeur = 5;
		else
			game->profondeur = 7;
	}
}
