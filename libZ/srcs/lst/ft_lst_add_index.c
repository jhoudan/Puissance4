/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:49:30 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:05:44 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Take a ptr on a list and add a link at the n-place in the list
**	since the start of the list and return a ptr on the element
*/

#include "libft.h"

t_list	*ft_lst_add_index(t_list *ptr_lst, t_list *lst_to_add, int index)
{
	t_list	*cur;

	cur = ptr_lst;
	cur = ft_lst_get_index(ft_lst_get_first(ptr_lst), index);
	if (!cur)
		return (NULL);
	cur = ft_lst_add_before(cur, lst_to_add);
	return (cur);
}
