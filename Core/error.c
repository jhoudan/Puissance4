/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:59:55 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 12:59:57 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int			ft_error(const char *s1, const char *s2, const char *s3)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(s3, 2);
	return (-1);
}
