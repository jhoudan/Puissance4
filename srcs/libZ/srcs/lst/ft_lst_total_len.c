/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_total_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:32:47 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:07:42 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calcul the size of a len since the first link
*/

#include "libft.h"

int		ft_lst_total_len(t_list *ptr_lst)
{
	return (ft_lst_len(ft_lst_get_first(ptr_lst)));
}
