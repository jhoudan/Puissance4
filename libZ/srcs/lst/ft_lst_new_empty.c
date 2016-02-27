/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:24:02 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:07:33 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Create a new link and duplicate the data and the key if they exists
**	Else they are set at NULL
*/

#include "libft.h"

t_list	*ft_lst_new_empty(void)
{
	t_list	*new_lst;

	new_lst = ft_memalloc(sizeof(t_list));
	new_lst->data = NULL;
	new_lst->next = NULL;
	new_lst->prev = NULL;
	return (new_lst);
}
