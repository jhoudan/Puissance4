/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:39:53 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:05:16 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Add the link after the ptr on the list set in first params
*/

#include "libft.h"

t_list		*ft_lst_add_after(t_list *lst_ptr, t_list *lst_to_add)
{
	lst_to_add->next = lst_ptr->next;
	lst_to_add->prev = lst_ptr;
	lst_ptr->next = lst_to_add;
	if (lst_to_add->next)
		(lst_to_add->next)->prev = lst_to_add;
	return (lst_to_add);
}
