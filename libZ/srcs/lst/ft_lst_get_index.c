/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:00:47 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:07:08 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Take a ptr on a list and return the i-ieme link after it
**	If i design an unvailable link, behavior is undefined
*/

#include "libft.h"

t_list	*ft_lst_get_index(t_list *ptr_lst, int index)
{
	t_list	*cur;

	cur = ft_lst_get_first(ptr_lst);
	while (--index)
	{
		if (cur == NULL || cur->next == NULL)
			return (NULL);
		cur = cur->next;
	}
	return (cur);
}
