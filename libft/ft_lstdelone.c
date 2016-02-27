/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:59:08 by mdezitte          #+#    #+#             */
/*   Updated: 2015/01/10 16:31:51 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list_libft **alst, void (*del)(void*, size_t))
{
	if (alst)
	{
		del(&((*alst)->content), (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
