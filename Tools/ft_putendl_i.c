/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:26:58 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/28 13:21:49 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_putendl_i(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
	return (0);
}
