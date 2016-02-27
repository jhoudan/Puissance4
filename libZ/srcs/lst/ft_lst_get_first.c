/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:41:27 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:07:00 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Take a pointer on a list and find the first link of the list
*/

#include "libft.h"

t_list	*ft_lst_get_first(t_list *ptr)
{
	t_list	*cur;

	cur = ptr;
	if (cur == NULL)
		return (NULL);
	while (cur->prev)
		cur = cur->prev;
	return (cur);
}
