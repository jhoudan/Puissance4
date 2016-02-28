/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 20:12:46 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/28 10:31:06 by jogarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <stdbool.h>
# include <fcntl.h>
# include <ncurses.h>
# include <errno.h>

# define WIN_VALUE		10000
# define IA				1
# define PLAYER			2

# define RED_DOT "\e[0;41m  \e[0m"
# define YELLOW_DOT "\e[0;43m  \e[0m"
/*
** Structure principal
*/
typedef struct	s_game
{
	int			column;
	int			line;
	int			**grid;
	int			ia;
	int			game_mode;
	int			profondeur;
	int			multi_players;
}				t_game;

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                                  CORE                                     |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

int				multi_player(t_game *game);
int				check_bot_right(t_game *game, int out, int line, int id);
int				check_bot_left(t_game *game, int out, int line, int id);

/*
** alloc_struct.c
*/
t_game			*init_game(void);
int				**fill_grid(int row, int column);

/*
** error.c
*/
int				ft_error(const char *s1, const char *s2, const char *s3);

/*
** free.c
*/
void			free_game(t_game *game);

/*
** init_game.c
*/
int				take_all_param_to_begin(t_game *game);

/*
** init_game_2.c
*/
void			select_multiplayers(t_game *game);

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                                  CHECK                                    |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

/*
** checker.c
*/
int				get_player_input(t_game *game);

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                                 TOOLS                                     |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

char			*read_one_line(int fd);
int				get_number(char *buff);

/*
**	Recurs_min_max (Debut du bordel)
*/
int				get_line_pos_when_put_the_piece(t_game grid, int column);
int				*get_valid_column(t_game game);
int				get_weight_pos_tab(t_game *game,
					int **weight_pos_tab, int player);
int				find_value_to_ret(t_game *game, int *values, int player);
int				recurs_get_column(t_game *game, int depth, int player);
int				get_column_to_play(t_game *game);
int				grid_is_full(t_game *game);

/*
**	Weight_pos
*/
typedef struct 		s_pos
{
	int				x;
	int				y;
}					t_pos;

int				ft_weight_pos(t_game *game, int column, int player);
int				ft_weight_player(t_game *game, int player, int column, int line);
int				ft_weight_not_player(t_game *game, int player, int column, int line);

/*
**	Fin du bordel merci
*/

void			put_in_grid(t_game *game, int put_in, int identifier);
t_game			*copy_struct_game(t_game *original);

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                                DISPLAY                                    |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

void			draw_grid(t_game *game);

/*
** ncurses
*/
void			ncurses_init(t_game *game);

#endif
