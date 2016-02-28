/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:51:36 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/28 16:13:04 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

static void		select_difficulty(t_game *game)
{
	char	*buff;

	while (42)
	{
		ft_putendl("\033[33mChoise your difficulty mode :");
		ft_putstr("Enter [\033[32measy\033[33m], [\033[32mnormal\033[33m]");
		ft_putstr(" or [\033[32mhard\033[33m] : \033[0m");
		if (!(buff = read_one_line(0)))
			return ;
		if (ft_strcmp(buff, "easy") == 0)
		{
			take_profondeur(game, 0);
			ft_strdel(&buff);
			break ;
		}
		if (ft_strcmp(buff, "normal") == 0)
		{
			take_profondeur(game, 1);
			ft_strdel(&buff);
			break ;
		}
		if (ft_strcmp(buff, "hard") == 0)
		{
			take_profondeur(game, 2);
			ft_strdel(&buff);
			break ;
		}
		ft_error("\033[31m[PARSE ERROR] : ", buff, " not valid\n");
		ft_strdel(&buff);
	}
}

static void		select_display_mode(t_game *game)
{
	char	*buff;

	while (42)
	{
		ft_putendl("\033[33mChoise your display mode :");
		ft_putstr("Enter [\033[32mshell\033[33m] for shell mode ");
		ft_putstr("[\033[32mgraphic\033[33m] for graphic mode : \033[0m");
		if (!(buff = read_one_line(0)))
			return ;
		if (ft_strcmp(buff, "shell") == 0)
		{
			game->game_mode = 1;
			ft_strdel(&buff);
			break ;
		}
		if (ft_strcmp(buff, "graphic") == 0)
		{
			game->game_mode = 2;
			ft_strdel(&buff);
			break ;
		}
		ft_error("\033[31m[PARSE ERROR] : ", buff, " not valid\n");
		ft_strdel(&buff);
	}
}

static void		select_column(t_game *game)
{
	char	*buff;

	while (42)
	{
		ft_putstr("\033[33mEnter number of column :\033[0m ");
		if (!(buff = read_one_line(0)))
			return ;
		game->column = get_number(buff);
		if (game->column < 7 || game->column > 50)
		{
			ft_error("\033[31m[PARSE ERROR]\033[0m : ",
				buff, "\n\033[31mIs not a valid");
			ft_putendl_fd(" argument take [7 - 50]", 2);
			ft_strdel(&buff);
		}
		else
		{
			ft_strdel(&buff);
			break ;
		}
	}
}

static void		select_line(t_game *game)
{
	char	*buff;

	while (42)
	{
		ft_putstr("\033[33mEnter number of line :\033[0m ");
		if (!(buff = read_one_line(0)))
			return ;
		game->line = get_number(buff);
		if (game->game_mode == 1 && (game->line < 6 || game->line > 30))
		{
			ft_error("\033[31m[PARSE ERROR]\033[0m : ",
				buff, "\n\033[31mIs not a valid");
			ft_putendl_fd(" argument take [6 - 30]", 2);
		}
		else if (game->game_mode == 2 && (game->line < 6 || game->line > 20))
		{
			ft_error("\033[31m[PARSE ERROR]\033[0m : ",
				buff, "\n\033[31mIs not a valid");
			ft_putendl_fd(" argument take [6 - 20]", 2);
		}
		else
			break ;
		ft_strdel(&buff);
	}
	ft_strdel(&buff);
}

int				take_all_param_to_begin(t_game *game)
{
	select_display_mode(game);
	if (game->game_mode == -1)
		return (1);
	select_column(game);
	if (game->column == -1)
		return (1);
	select_line(game);
	if (game->line == -1)
		return (1);
	select_multiplayers(game);
	if (game->multi_players == -1)
		return (1);
	if (game->multi_players == 1)
	{
		select_difficulty(game);
		if (game->profondeur == -1)
			return (1);
	}
	srand(time(NULL));
	game->ia = (rand() % 2) + 1;
	if (game->ia == 1 && game->multi_players == 1)
		ft_putendl("\033[31mIA Start a Game\033[0m");
	if (game->ia == 2 && game->multi_players == 1)
		ft_putendl("\033[31mYou Start a Game\033[0m");
	return (0);
}
