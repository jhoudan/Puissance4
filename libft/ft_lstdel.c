/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:04:08 by mdezitte          #+#    #+#             */
/*   Updated: 2015/01/10 16:31:39 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list_libft **alst, void (*del)(void*, size_t))
{
	if (!alst || !*alst)
		return ;
	ft_lstdel(&((*alst)->next), del);
	ft_lstdelone(alst, del);
}
