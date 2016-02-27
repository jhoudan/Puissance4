/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_one_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:11:21 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/27 17:26:26 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance.h>

static int	get_more_size(char **str, int size)
{
	char	*tmp;

	if (!*str)
		*str = ft_strnew(25);
	else
	{
		tmp = ft_strnew(size + 25);
		ft_strcpy(tmp, *str);
		ft_strdel(str);
		*str = tmp;
	}
	return (size + 25);
}

static char	*print_read_error(void)
{
	ft_putstr("\n\033[31mPuissance4: critical error -> ");
	ft_putstr(strerror(errno));
	ft_putstr("\033[0m\n");
	return (NULL);
}

char		*read_one_line(int fd)
{
	char	*str;
	char	buffer[26];
	int		size;
	int		ret;

	size = 25;
	str = ft_strnew(25);
	ft_memset(buffer, 0, 26);
	errno = 0;
	while ((ret = read(fd, buffer, 25)) > 0)
	{
		if (ret + size > size)
			size = get_more_size(&str, size);
		ft_strcat(str, buffer);
		if (ft_strchr(str, '\n'))
		{
			(ft_strchr(str, '\n'))[0] = 0;
			break ;
		}
		ft_memset(buffer, 0, 26);
	}
	if (ret == -1)
		return (print_read_error());
	return (str);
}
