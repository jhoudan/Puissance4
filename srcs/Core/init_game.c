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

#include "../../includes/puissance.h"

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

static int		select_column(t_game *game)
{
	char	*buff;

	ft_putstr("\033[33mEnter number of column :\033[0m ");
	get_next_line(0, &buff);
	game->column = get_number(buff);
	if (game->column < 7 || game->column > 50)
	{
		ft_error("\033[31m[PARSE ERROR]\033[0m : ", buff, "\nIs not a valid");
		ft_putendl_fd(" argument take [7 - 50]", 2);
		ft_strdel(&buff);
		return (-1);
	}
	ft_strdel(&buff);
	return (0);
}

static int 		select_line(t_game *game)
{
	char	*buff;

	ft_putstr("\033[33mEnter number of line :\033[0m ");
	get_next_line(0, &buff);
	game->line = get_number(buff);
	if (game->line < 6)
	{
		ft_error("\033[31m[PARSE ERROR]\033[0m : ", buff, "\nIs not a valid");
		ft_putendl_fd(" argument take [6 - 50]", 2);
		ft_strdel(&buff);
		return (-1);
	}
	ft_strdel(&buff);
	return (0);
}

int				take_all_param_to_begin(t_game *game)
{
	if (select_column(game) == -1)
		take_all_param_to_begin(game);
	if (select_line(game) == -1)
		take_all_param_to_begin(game);
	return (0);	
}
