/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:13:29 by mdezitte          #+#    #+#             */
/*   Updated: 2016/01/30 17:48:13 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_make_join(char **s1, const char *s2)
{
	char	*tmp;

	tmp = ft_strdup(*s1);
	ft_strdel(s1);
	*s1 = ft_strjoin(tmp, s2);
	ft_strdel(&tmp);
}
