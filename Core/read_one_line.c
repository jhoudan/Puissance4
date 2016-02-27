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

char	*read_one_line(int fd)
{
	char	*str;
	char	buffer[26];
	int		size;
	int		ret;

	size = 0;
	str = NULL;
	ft_memset(buffer, 0, 26);
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
	return (str);
}
