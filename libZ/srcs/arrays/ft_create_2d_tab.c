/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_2d_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:08:51 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:04:04 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Create a tab with x dimensions
*/

#include "libft.h"

void	*ft_create_2d_tab(size_t size)
{
	return (ft_memalloc(size + 1));
}
