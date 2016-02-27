/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clr_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:47:49 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:06:24 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Set as clear all the member of the struct in the link
**	Data is clear with the function clr
*/

#include "libft.h"

t_list	*ft_lst_clr_one(t_list *lst, void (*clr)(void *))
{
	if (lst)
	{
		(*clr)(lst->data);
		lst->next = NULL;
		lst->prev = NULL;
	}
	return (lst);
}
