/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:46:39 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:06:43 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Del and free the list since the link sent in params
**	Return a pointer on the prev member
*/

#include "libft.h"

t_list		*ft_lst_del(t_list **lst_to_del, void (*del)(void **))
{
	t_list	*cur;

	cur = (*lst_to_del)->prev;
	while (*lst_to_del)
		*lst_to_del = ft_lst_del_one(lst_to_del, (*del));
	return (cur);
}
