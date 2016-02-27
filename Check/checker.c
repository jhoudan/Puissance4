/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:07:49 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 17:30:08 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance.h>

static int	is_valid_input(int input, t_game *game)
{
	if (input < 0 || input >= game->column)
	{
		ft_putendl("\033[31mIs out of range\033[0m");
		return (0);
	}
	else if (game->grid[0][input] != 0)
	{
		ft_putendl("\033[31mIs already full\033[0m");
		return (0);
	}
	return (1);
}

static int	ft_isnumber(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_putendl("\033[31mIs not a number\033[0m");
			return (0);
		}
		str++;
	}
	return (1);
}

static int	ask_for_input(t_game *game)
{
	ft_putstr("\033[32m\nPick a column between 0 and ");
	ft_putnbr(game->column - 1);
	ft_putstr(": \033[0m");
	return (1);
}

int			get_player_input(t_game *game)
{
	int		input;
	char	*line;

	line = NULL;
	while (42)
	{
		ask_for_input(game);
		line = read_one_line(0);
		if (line && ft_isnumber(line))
		{
			input = ft_atoi(line);
			if (is_valid_input(input, game))
			{
				ft_strdel(&line);
				break ;
			}
		}
		ft_strdel(&line);
	}
	return (input);
}
