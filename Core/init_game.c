/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:51:36 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 12:51:37 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

static int		get_number(char *buff)
{
	int		i;

	i = 0;
	if (ft_strlen(buff) > 2)
		return (-1);
	while (buff[i])
	{
		if (ft_isdigit(buff[i]) == 0)
			return (-1);
		i++;
	}
	i = ft_atoi(buff);
	return (i);
}

static void		select_display_mode(t_game *game)
{
	char	*buff;

	while (42)
	{
		ft_putendl("\033[33mChoise your display mode :");
		ft_putstr("Enter [shell] for shell mode [graphic] for graphic mode :");
		get_next_line(0, &buff);
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
		get_next_line(0, &buff);
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
		get_next_line(0, &buff);
		game->line = get_number(buff);
		if (game->line < 6 || game->line > 50)
		{
			ft_error("\033[31m[PARSE ERROR]\033[0m : ",
				buff, "\n\033[31mIs not a valid");
			ft_putendl_fd(" argument take [6 - 50]", 2);
			ft_strdel(&buff);
		}
		else
		{
			ft_strdel(&buff);
			break ;
		}
	}
}

int				take_all_param_to_begin(t_game *game)
{
	select_column(game);
	select_line(game);
	select_display_mode(game);
	srand(time(NULL));
	game->ia = (rand() % 2) + 1;
	return (0);
}
