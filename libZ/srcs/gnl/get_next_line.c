/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 18:58:47 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 12:27:52 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_all_line(char **line, char **str_fd, int fd)
{
	int		ret;
	char	*str_read;

	str_read = ft_strnew(BUFF_SIZE);
	str_read = ft_strcpy(str_read, *str_fd);
	while (ft_strchr(str_read, '\n') == NULL)
	{
		*line = ft_strfjoin(line, str_read);
		ft_strclr(str_read);
		if ((ret = read(fd, str_read, BUFF_SIZE)) == -1)
			return (-1);
		else if (ret == 0)
		{
			ft_strdel(&str_read);
			ft_strdel(str_fd);
			return ((**line == '\0') ? 0 : 1);
		}
	}
	*str_fd = str_read;
	return (2);
}

int					get_next_line(const int fd, char **line)
{
	static char	*str_fd[MAX_FD];
	char		*tmp;
	int			ret;

	if (line == NULL || (*line = ft_strnew(0)) == NULL || fd < 0 || fd > MAX_FD)
		return (-1);
	if (str_fd[fd] == NULL)
		if ((str_fd[fd] = ft_strnew(BUFF_SIZE)) == NULL)
			return (-1);
	if (ft_strchr(str_fd[fd], '\n') == NULL)
	{
		if ((ret = get_all_line(line, &str_fd[fd], fd)) != 2)
			return (ret);
	}
	*line = ft_strcfjoin(line, str_fd[fd], '\n');
	tmp = ft_strsub(str_fd[fd], ft_strclen(str_fd[fd], '\n') + 1,
		ft_strlen(str_fd[fd] + ft_strclen(str_fd[fd], '\n') + 1));
	ft_strdel(&(str_fd[fd]));
	str_fd[fd] = tmp;
	return (1);
}
