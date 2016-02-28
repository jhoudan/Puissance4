#include "../includes/puissance.h"

static int		reverse_player(int player)
{
	if (player == 1)
		return (2);
	if (player == 2)
		return (1);
	return (0);
}

int				ft_weight_pos(t_game *game, int column, int player)
{
	int		line;
	int		weight;

	line = get_line_pos_when_put_the_piece(*game, column);
	weight = 0;
	weight += ft_weight_player(game, player, column, line);
	weight += ft_weight_not_player(game, reverse_player(player), column, line);
	return (weight);
}
