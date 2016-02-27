/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_before.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 10:44:51 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:05:24 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_add_before(t_list *lst_ptr, t_list *lst_to_add)
{
	lst_to_add->prev = lst_ptr->prev;
	lst_to_add->next = lst_ptr;
	if (lst_ptr->prev)
		lst_ptr->prev->next = lst_to_add;
	lst_ptr->prev = lst_to_add;
	return (lst_to_add);
}
