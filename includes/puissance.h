/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 20:12:46 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/28 13:19:57 by jhoudan          ###   ########.fr       */
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
# include <errno.h>
# include <curses.h>
# include <assert.h>

# define WIN_VALUE		100000
# define IA				1
# define PLAYER			2

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

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                                 CHECK                                     |
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
** |                                  CORE                                     |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

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
void			take_profondeur(t_game *game, int values);

/*
** init_game_2.c
*/
void			select_multiplayers(t_game *game);

/*
** put_in_grid.c
*/
void			put_in_grid(t_game *game, int put_in, int identifier);

/*
** shell_game_manager.c
*/
int				shell_game_manager(t_game *game);

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                                  DISPLAY                                  |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

/*
** drawshell.c
*/
void			draw_grid(t_game *game);

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                                 MULTI                                     |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

/*
** multi_player.c
*/
int				check_if_win(t_game *game, int out, int id);
int				multi_player(t_game *game);

/*
** multi_player_2.c
*/
int				check_bot_left(t_game *game, int out, int line, int id);
int				check_bot_right(t_game *game, int out, int line, int id);

/*
** check_if_win.c
*/
int				check_if_win(t_game *game, int out, int id);

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                                 NCURSES                                   |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

/*
** ncurses_display.c
*/
void			ncurses_init(t_game *game);

/*
** key.c
*/
int				key_manager(int key, t_game *game);
void			check_scr_size(t_game *game);

/*
** drawer.c
*/
void			put_vals(t_game *game);
void			draw_grid_ncurses(t_game *game);

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                             RECURS_MIN_MAX                                |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

/*
** find_value_to_ret.c
*/
int				find_value_to_ret(t_game *game, int *values, int player);

/*
** get_column_to_play.c
*/
int				recurs_get_column(t_game *game, int depth, int player);
int				get_column_to_play(t_game *game);

/*
** get_line_pos_when_put_the_piece.c
*/
int				get_line_pos_when_put_the_piece(t_game game, int column);

/*
** get_valid_column.c
*/
int				*get_valid_column(t_game game);

/*
** get_weight_pos_tab.c
*/
int				get_weight_pos_tab(t_game *game,
					int **weight_pos_tab, int player);

/*
** grid_is_full.c
*/
int				grid_is_full(t_game *game);

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                                 TOOLS                                     |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

/*
** copy_struct_game.c
*/
t_game			*copy_struct_game(t_game *original);

/*
** read_one_line.c
*/
char			*read_one_line(int fd);

/*
** tools.c
*/
int				get_number(char *buff);
int				ft_putendl_i(char *str);

/*
** |----------------------------------------------------------------------------
** |                                                                           |
** |                             WEIGHT_VALUES                                 |
** |                                                                           |
** |----------------------------------------------------------------------------
*/

/*
** ft_weight.c
*/
int				ft_weight_pos(t_game *game, int column, int player);
int				ft_conv(int value, int option);

/*
** ft_weight_not_player.c
*/
int				ft_weight_not_player(t_game *game, int player,
					int column, int line);

/*
** ft_weight_player.c
*/
int				ft_weight_player(t_game *game, int player,
	int column, int line);

#endif
