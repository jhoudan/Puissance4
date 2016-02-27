/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:24:20 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:05:37 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Add a link at the end of the lst
*/

#include "libft.h"

void	ft_lst_add_end(t_list *lst, t_list *lst_to_add)
{
	t_list	*cur;

	cur = ft_lst_get_last(lst);
	cur->next = lst_to_add;
	lst_to_add->prev = cur;
}
