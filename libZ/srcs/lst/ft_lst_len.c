/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:28:07 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:07:20 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calcul the len of a lst since the link set in params
*/

#include "libft.h"

int		ft_lst_len(t_list *lst_ptr)
{
	int		n;
	t_list	*cur;

	n = 0;
	cur = lst_ptr;
	while (cur)
	{
		cur = cur->next;
		n++;
	}
	return (n);
}
