/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:44:11 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:10:01 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Put at most n char on the file descriptor set in params
*/

#include "libft.h"

void	ft_putnstr_fd(const char *s, size_t n)
{
	if (n < ft_strlen(s))
		write(1, s, n);
	else
		write(1, s, ft_strlen(s));
}
