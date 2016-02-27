/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 20:12:46 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 17:22:06 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <stdbool.h>
# include <term.h>
# include <fcntl.h>
# include <errno.h>

# define WIN_VALUE		10000

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
}				t_game;

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
**	Recurs_min_max
*/
int				get_line_pos_when_put_the_piece(t_game grid, int column);
int				*get_valid_columns(t_game game);
int				get_nb_valide_columns(t_game *game);


void			put_in_grid(t_game *game, int put_in);

#endif
