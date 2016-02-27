/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clr_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:15:25 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:06:11 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Set all te link as clear in the linked chain
*/

#include "libft.h"

void	ft_lst_clr_all(t_list *lst, void (*clr)(void *))
{
	ft_lst_clr(ft_lst_get_first(lst), (*clr));
}
