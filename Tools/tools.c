/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 16:49:55 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 16:50:11 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int		get_number(char *buff)
{
	int		i;

	i = 0;
	if (ft_strlen(buff) > 2)
		return (-1);
	while (buff[i])
	{
		if (ft_isdigit(buff[i]) == 0)
			return (-1);
		i++;
	}
	i = ft_atoi(buff);
	return (i);
}
