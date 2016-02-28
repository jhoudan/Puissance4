#include "../ft_weight.h"

static int		stc_check_line(t_game *game, int player, t_pos *pos);
static int 		stc_check_column(t_game *game, int player, t_pos *pos);
static int		stc_check_diag_SO_NE(t_game *game, int player, t_pos *pos);
static int		stc_check_diag_NO_SE(t_game *game, int player, t_pos *pos);


/*
**  	------------------------------------------------------
**  	|						MAIN	        	         |
**  	------------------------------------------------------
*/

int			ft_weigth_not_player(t_game *game, int player, int column , int line)
{
	int		weight;
	t_pos	pos;

	pos.y = line;
	pos.x = column;
	weight = 0;
	weight += stc_check_line(game, player, &pos);
	weight += stc_check_column(game, player, &pos);
	weight += stc_check_diag_SO_NE(game, player, &pos);
	weight += stc_check_diag_NO_SE(game, player, &pos);
	return (weight);
}

/*
**  	------------------------------------------------------
**  	|						Static	        	         |
**  	------------------------------------------------------
*/

// DOING FUNCTION TO CHANGE VALUE -> REAL WEIGHT

static int		stc_check_line(t_game *game, int player, t_pos *pos)
{
	int		**grid;
	int		ret;
	int		value;
	int		x;

	grid = game->grid;
	ret = 0;
	x = pos->x;
	while (++x < game->column && grid[pos->y][x] == player)
		ret++;
	x = pos->x;
	while (--x > 0 && grid[pos->y][x] == player)
		ret++;
	return (ret);
}

static int 		stc_check_column(t_game *game, int player, t_pos *pos)
{
	int		**grid;
	int		ret;
	int		value;
	int		y;

	grid = game->grid;
	ret = 0;
	y = pos->y;
	while (++y < game->column && grid[y][pos->x] == player)
		ret++;
	y = pos->y;
	while (--y > 0 && grid[y][pos->x] == player)
		ret++;
	return (value);
}

static int		stc_check_diag_SO_NE(t_game *game, int player, t_pos *pos)
{
	int		**grid;
	int		ret;
	int		y;
	int		x;

	grid = game->grid;
	ret = 0;
	y = pos->y;
	x = pos->x;
	while (++y > 0 && ++x >= 0 && grid[y][x] == player)
		ret++;
	y = pos->y;
	x = pos->x;
	while (--y > 0 && --x >= 0 && grid[y][x] == player)
		ret++;
	return (ret);
}

static int		stc_check_diag_NO_SE(t_game *game, int player, t_pos *pos)
{
	int		**grid;
	int		ret;
	int		y;
	int		x;

	grid = game->grid;
	ret = 0;
	y = pos->y;
	x = pos->x;
	while (++y < game->line && --x >= 0 && grid[y][x] == player)
		ret++;
	y = pos->y;
	x = pos->x;
	while (--y >= 0 && ++x < game->column && grid[y][x] == player);
		ret++;
	return (ret);
}
