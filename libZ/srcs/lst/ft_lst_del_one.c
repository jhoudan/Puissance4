/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:46:33 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:06:51 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Del and free the link and sent a pointer on the next one
*/

#include "libft.h"

t_list	*ft_lst_del_one(t_list **lst_to_del, void (*del)(void **))
{
	t_list	*next;

	next = (*lst_to_del)->next;
	if ((*lst_to_del)->next)
		(*lst_to_del)->next->prev = (*lst_to_del)->prev;
	if ((*lst_to_del)->prev)
		(*lst_to_del)->prev->next = (*lst_to_del)->next;
	(*del)(&((*lst_to_del)->data));
	ft_memdel((void **)lst_to_del);
	return (next);
}
