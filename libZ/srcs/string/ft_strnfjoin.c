/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnfjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:59:29 by mressier          #+#    #+#             */
/*   Updated: 2016/02/26 12:59:30 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnfjoin(char **s1, const char *s2, size_t n)
{
	char	*new_str;
	char	*dup_s1;
	int		len;

	dup_s1 = ft_strdup(*s1);
	new_str = ft_strnjoin(dup_s1, s2, n);
	ft_strdel(&dup_s1);
	ft_strdel(s1);
	return (new_str);
}
