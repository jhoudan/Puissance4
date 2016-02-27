/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 20:12:46 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 14:13:43 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

# include "../libZ/includes/libft.h"
# include "color.h"
# include <stdlib.h>

/*
** Structure principal
*/
typedef struct	s_game
{
	int			column;
	int			line;
	int			**grid;
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
int				**fill_grid(int row, int column);
int				delete_grid(int **grid, int row);

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
int				get_input_player(t_game *game);

#endif
