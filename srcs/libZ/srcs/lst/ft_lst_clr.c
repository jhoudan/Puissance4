/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:47:04 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:06:00 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Set as clear all the link since the one set in params
**	Data is clear with the function clr
*/

#include "libft.h"

t_list	*ft_lst_clr(t_list *lst, void (*clr)(void *))
{
	t_list	*cur;
	t_list	*tmp;

	cur = lst;
	while (cur)
	{
		tmp = cur->next;
		ft_lst_clr_one(cur, (*clr));
		cur = tmp;
	}
	return (lst);
}
