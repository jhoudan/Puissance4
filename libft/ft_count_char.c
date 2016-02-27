/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:38:08 by mdezitte          #+#    #+#             */
/*   Updated: 2016/01/30 17:38:11 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_char(char *source, const char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (source[i])
	{
		if (source[i] == c)
			nb++;
		i++;
	}
	return (nb);
}
