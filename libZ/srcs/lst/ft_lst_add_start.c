/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:52:56 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:05:52 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Take a list and add the link at the start of the chained list and return
**	a pointer on this first link
*/

#include "libft.h"

t_list	*ft_lst_add_start(t_list *ptr_lst, t_list *lst_to_add)
{
	t_list	*cur;

	cur = ft_lst_get_first(ptr_lst);
	lst_to_add->next = cur;
	cur->prev = lst_to_add;
	return (cur);
}
