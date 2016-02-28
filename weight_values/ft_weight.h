#ifndef FT_WEIGHT_POS_H
#define FT_WEIGHT_POS_H

#include "includes/puissance.h"

typedef struct 		s_pos
{
	int				x;
	int				y;
}					t_pos;

// PRINCIPAL FUCNTION
int				ft_weigth_pos(t_game *game, int column, int player);
int				ft_weight_player(t_game *game, int player, int column, int line);
int				ft_weight_not_player(t_game *game, int player, int column, int line);

// SECONDARY FUNCTION


// ALREADY DO BY MRESSIER
int				ft_get_line(t_game *game, int player, t_pos *pos);

#endif
