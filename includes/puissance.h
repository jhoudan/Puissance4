/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 20:12:46 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 12:24:39 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

# include "../libZ/includes/libft.h"
# include <stdlib.h>

typedef struct	s_game
{
	int			collumn;
	int			line;
}				t_game;

int				game_core(t_game *game);

#endif
