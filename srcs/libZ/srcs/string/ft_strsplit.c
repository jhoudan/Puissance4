/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:25:50 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:14:36 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Return an array of string create by the split of the s with the char c
** s = "hello les moches" with the char ' ' make "hello" "les" "moches"
*/

#include "libft.h"

static int	count_word(const char *s, int c)
{
	int		n;

	n = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			n++;
		s++;
	}
	return (n);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i_tab;
	int		i_s;
	int		len;
	char	**tab;

	i_tab = 0;
	i_s = 0;
	tab = (char **)ft_create_2d_tab(sizeof(char *) * count_word(s, c));
	while (s[i_s])
	{
		if (s[i_s] != c && (s[i_s - 1] == c || i_s == 0))
		{
			len = ft_strclen(&s[i_s], c);
			(len == -1) ? len = ft_strlen(&s[i_s]) : 0;
			tab[i_tab++] = ft_strsub(s, i_s, len);
			i_s += len;
		}
		else
			i_s++;
	}
	tab[i_tab] = NULL;
	return (tab);
}
