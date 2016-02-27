#include <puissance.h>

int		multi_player(t_game *game)
{
	int	input;
	int	max;
	int	i;

	max = game->column * game->line;
	i = -1;
	while (++i < max)
	{
		input = get_player_input(game);
		if (i % 2 == 0)
			put_in_grid(game, input, IA);
		else
			put_in_grid(game, input, PLAYER);
		draw_grid(game);
	}
	ft_putstr("Match nul !\n");
	return (1);
}
