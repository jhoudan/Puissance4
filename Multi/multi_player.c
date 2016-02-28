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

#include <puissance.h>

static int	check_column(t_game *game, int out, int line, int id)
{
	int i;
	int nb_piece;

	i = 1;
	nb_piece = 1;
	while (line + i < game->line && game->grid[line + i][out] == id)
		i++;
	nb_piece += i - 1;
	return (nb_piece);
}

static int	check_line(t_game *game, int out, int line, int id)
{
	int i;
	int	nb_piece;

	i = 1;
	nb_piece = 1;
	while (out + i < game->column && game->grid[line][out + i] == id)
		i++;
	nb_piece += i - 1;
	i = 1;
	while (out - i >= 0 && game->grid[line][out - i] == id)
		i++;
	nb_piece += i - 1;
	return (nb_piece);
}

static int	take_last_piece(t_game *game, int out)
{
	int		line;

	line = 0;
	while (line < game->line)
	{
		if (game->grid[line][out] != 0)
			return (line);
		line++;
	}
	return (line);
}

int			check_if_win(t_game *game, int out, int id)
{
	int line;

	line = take_last_piece(game, out);
	if (check_column(game, out, line, id) >= 4)
		return (1);
	if (check_line(game, out, line, id) >= 4)
		return (1);
	if (check_bot_left(game, out, line, id) >= 4)
		return (1);
	if (check_bot_right(game, out, line, id) >= 4)
		return (1);
	return (0);
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
	}
	ft_putstr("\033[34mMatch nul !\033[0m\n");
	return (1);
}
