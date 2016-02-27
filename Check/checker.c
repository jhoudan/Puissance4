#include <puissance.h>

static int	is_valid_input(int input, t_game *game)
{
	if (input < 0 || input >= game->column)
	{
		ft_putendl("Is out of range");
		return (0);
	}
	else if (game->grid[0][input] != 0)
	{
		ft_putendl("Is already full");
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
			ft_putendl("Is not a number");
			return (0);
		}
		str++;
	}
	return (1);
}

static int	print_grid_limit(t_game *game)
{
	ft_putstr("Please pick a column between 0 and ");
	ft_putnbr(game->column - 1);
	ft_putstr(": ");
	return (1);
}

int			get_player_input(t_game *game)
{
	int		input;
	char	*line;

	line = NULL;
	ft_putstr("Pick a column: ");
	while (42)
	{
		get_next_line(STDIN_FILENO, &line);
		if (line && ft_isnumber(line))
		{
			input = ft_atoi(line);
			if (is_valid_input(input, game))
				break ;
		}
		ft_strdel(&line);
		print_grid_limit(game);
	}
	if (line)
		ft_strdel(&line);
	return (input);
}
