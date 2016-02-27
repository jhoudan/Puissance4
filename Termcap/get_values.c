/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:11:12 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 15:11:13 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

bool	is_echap(const char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0)
		return (true);
	else
		return (false);
}

bool	is_enter(const char *buffer)
{
	if (buffer[0] == 10 && buffer[1] == 0 && buffer[2] == 0)
		return (true);
	else
		return (false);
}

bool	is_alpha(const char *buffer)
{
	if (buffer[0] > 47 && buffer[0] < 58 && buffer[1] == 0 && buffer[2] == 0)
		return (true);
	else
		return (false);
}
