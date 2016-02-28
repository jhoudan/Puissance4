/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 19:07:55 by mressier          #+#    #+#             */
/*   Updated: 2016/02/28 19:07:56 by mressier         ###   ########.fr       */
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
