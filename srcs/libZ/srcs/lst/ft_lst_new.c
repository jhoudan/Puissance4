/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:17:15 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:07:26 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Create a new link t_list and set it with data
*/

#include "libft.h"

t_list	*ft_lst_new(void *data, size_t size)
{
	t_list	*new_lst;

	new_lst = ft_lst_new_empty();
	new_lst->data = ft_memdup(data, size);
	return (new_lst);
}
