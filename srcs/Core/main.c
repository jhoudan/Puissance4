/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:15:51 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 12:43:15 by mdezitte         ###   ########.fr       */
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
	free(game);
	game = NULL;
}

static t_game	*init_game(void)
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	game->collumn = -1;
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
		if (ft_isdigit(buff[i]) == 0)
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
	ft_putendl("Enter number of collumn [7 - 99] :");
	get_next_line(0, &buff);
	game->collumn = get_number(buff);
	ft_strdel(&buff);
	ft_putendl("Enter number of line [6 - 99] :");
	get_next_line(0, &buff);
	game->line = get_number(buff);
	ft_strdel(&buff);
	if (game->line < 6 || game->collumn < 7)
	{
		ft_putendl_fd("Parse error, enter number [X - 99] thanks", 2);
		free_game(game);
		return (-1);
	}
	result = 0;
	//result = game_core(game);
	print_result(result);
	free_game(game);
	return (0);
}