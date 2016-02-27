/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:02:37 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:04:59 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return (c == '\n' || c == '\t' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ');
}
