/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 11:42:01 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/23 11:36:06 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>

char		get_file_type(char *path)
{
	struct stat		buff;
	char			c;

	if (stat(path, &buff) == -1)
		return ('\0');
	c = '0';
	if (S_ISDIR(buff.st_mode))
		c = 'd';
	else if (S_ISFIFO(buff.st_mode))
		c = 'p';
	else if (S_ISCHR(buff.st_mode))
		c = 'c';
	else if (S_IFLNK & buff.st_mode)
	{
		if (S_ISREG(buff.st_mode))
			c = '-';
		else if (S_ISBLK(buff.st_mode))
			c = 'b';
		else if (S_ISSOCK(buff.st_mode))
			c = 's';
		else
			c = 'l';
	}
	return (c);
}
