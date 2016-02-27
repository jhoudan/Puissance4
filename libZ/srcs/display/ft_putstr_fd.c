/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:38:51 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:10:20 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Put s on the file descriptor set in params
*/

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
