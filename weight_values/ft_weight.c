#include "../ft_weight.h"

int		ft_weight_pos(t_game *game, int column, int player)
{
	int		line;
	int		weigth;
	int		**grid;

	line = ft_get_line(game, column);
	weigth = 0;
	weigth += ft_weight_player(game, player, column, line);
	//weigth += ft_weigth_not_player(game, reverse_player(player), column, line);
}

int		reverse_player(int player)
{
	if (player == 1)
		return (2);
	if (player == 2)
		return (1);
	return (0);
}

// static int		stc_check_line(t_game *game, int player, t_pos *pos, int ret)
// {
// 	int		**grid;

// 	grid = game->grid;
// 	if (ret != stc_check_line(game, player, pos, ret) && ((pos->x)++) != -1)
// 		ret = stc_check_line(game, player, pos, ret++);
// 	(pos->x)--;
// 	if (ret != stc_check_line(game, player, pos, ret) && ((pos->x)--) != -1)
// 		ret = stc_check_line(game, player, pos, ret++);

// 	if (grid[pos->y][pos->x] == player)
// 		return (1 + ret);
// 	return (0 + ret);
// }