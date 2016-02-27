/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 20:12:46 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 13:15:50 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

# include "../libZ/includes/libft.h"
# include "color.h"
# include <stdlib.h>

typedef struct	s_game
{
	int			column;
	int			line;
	int			**grid;
}				t_game;

int				game_core(t_game *game);

int				get_input_player(t_game *game);

#endif
