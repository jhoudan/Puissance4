/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:40:31 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/16 14:13:45 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static int			return_value(int i, char **tmp)
{
	if (**tmp)
		ft_strdel(tmp);
	return (i);
	(void)tmp;
}

static int			ft_solve(t_box *box, char **line, int fd)
{
	int				i;

	i = 0;
	if (box->fd != fd)
		box->fd = fd;
	while (box->tmp[i])
	{
		if (box->tmp[i] == '\n')
		{
			*line = ft_strsub(box->tmp, 0, i);
			i++;
			box->tmp = ft_strcpy(box->tmp, &(box->tmp[i]));
			return (1);
		}
		i++;
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_box	box;

	if (fd < 0 || fd >= 99 || (fd == 1 && line == NULL) || BUFF_SIZE <= 0
			|| line == NULL)
		return (-1);
	if (box.tmp == NULL)
		box.fd = fd;
	if (!box.tmp)
		box.tmp = ft_strnew(0);
	while ((box.ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[box.ret] = '\0';
		ft_make_join(&box.tmp, buf);
		if (ft_solve(&box, line, fd) == 1)
			return (return_value(1, &box.tmp));
	}
	if (box.ret < 0)
		return (return_value(-1, &box.tmp));
	if (ft_solve(&box, line, fd) == 1)
		return (return_value(1, &box.tmp));
	*line = ft_strcpy(box.tmp, box.tmp);
	return (return_value(0, &box.tmp));
}
