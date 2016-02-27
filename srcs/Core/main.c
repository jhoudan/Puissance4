/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:15:51 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 13:45:44 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/puissance.h"

static void		print_result(int status)
{
	if (status == 1)
		ft_putendl("Congrats, it's win");
	if (status == 0)
		ft_putendl("Match nul !");
	if (status == -1)
		ft_putendl("You loose !");
}

static void		free_game(t_game *game)
{
	delete_grid(game->grid, game->line, game->column);
	free(game);
	game = NULL;
}

static t_game	*init_game(void)
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	game->column = -1;
	game->line = -1;
	return (game);
}

static int		get_number(char *buff)
{
	int		i;

	i = 0;
	if (ft_strlen(buff) > 2)
		return (-1);
	while (buff[i])
	{
		if (ft_isdigit(buff[i]) == 0 && buff[i] != '\n') // FIX TEMPORAIRE
			return (-1);
		i++;
	}
	i = ft_atoi(buff);
	return (i);
}

int				main(void)
{
	t_game	*game;
	char	*buff;
	int		result;

	game = init_game();
	ft_putendl("Enter number of column [7 - 99] :");
	get_next_line(0, &buff);
	game->column = get_number(buff);
	ft_strdel(&buff);
	ft_putendl("Enter number of line [6 - 99] :");
	get_next_line(0, &buff);
	game->line = get_number(buff);
	ft_strdel(&buff);
	if (game->line < 6 || game->column < 7)
	{
		ft_putendl_fd("Parse error, enter number [X - 99] thanks", 2);
		free_game(game);
		return (-1);
	}
	result = 0;
	game->grid = fill_grid(game->line, game->column);
	get_input_player(game);
	//result = game_core(game);
	print_result(result);
	free_game(game);
	return (0);
}
