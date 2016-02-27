/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:41:18 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:07:14 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Take a ptr on a list and find the last link of the chained link
*/

#include "libft.h"

t_list	*ft_lst_get_last(t_list *ptr)
{
	t_list	*cur;

	cur = ptr;
	while (cur->next)
		cur = cur->next;
	return (cur);
}
