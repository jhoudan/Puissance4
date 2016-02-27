/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:54:16 by mressier          #+#    #+#             */
/*   Updated: 2016/02/03 11:04:50 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ullitoa_base(unsigned long long int nb, size_t base)
{
	size_t					len;
	char					*ret;
	int						mod;

	if ((int)(len = ft_unsigned_len(nb, base)) == -1)
		return (NULL);
	ret = ft_strnew(len);
	while (nb > base - 1)
	{
		mod = nb % base;
		ret[--len] = (mod < 10) ? mod + 48 : mod + 87;
		nb /= base;
	}
	ret[--len] = (nb < 10) ? nb + 48 : nb + 87;
	return (ret);
}
