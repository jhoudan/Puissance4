/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 13:01:25 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:11:54 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Clean the memory
*/

#include "libft.h"

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}