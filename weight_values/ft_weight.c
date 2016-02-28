#include "../includes/puissance.h"

static int		reverse_player(int player);

/*
**  	------------------------------------------------------
**  	|						MAIN	        	         |
**  	------------------------------------------------------
*/

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

int		ft_conv(int value, int option)
{
	int		conv;

	if (option == 1)
	{
		conv = (value == 1) ? 10 : 0;
		conv = (value == 2) ? 100 : 0;
		conv = (value == 3) ? 1000 : 0;
		conv = (value >= 4) ? 100000 : 0;
	}
	if (option == 2)
	{
		conv = (value == 1) ? 45 : 0;
		conv = (value == 2) ? 1900 : 0;
		conv = (value >= 3) ? 10000 : 0;
	}
	return (conv);
}

/*
**  	------------------------------------------------------
**  	|						Static	        	         |
**  	------------------------------------------------------
*/

static int		reverse_player(int player)
{
	if (player == 1)
		return (2);
	if (player == 2)
		return (1);
	return (0);
}