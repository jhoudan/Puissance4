/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:10:59 by mdezitte          #+#    #+#             */
/*   Updated: 2016/02/27 15:11:01 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int		ft_print(int c)
{
	int		fd;

	fd = open("/dev/tty", O_RDWR);
	ft_putchar_fd(c, fd);
	close(fd);
	return (0);
}

void	set_terminal_mode(t_game *game)
{
	struct termios	tattr;

	ft_putstr_fd("\033[?1049h\033[H", game->fd);
	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ECHO | ICANON);
	tattr.c_oflag &= ~(OPOST);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tgetent(NULL, getenv("TERM"));
}

void	unset_terminal_mode(t_game *game)
{
	struct termios tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag |= (ECHO | ICANON);
	tattr.c_oflag |= (OPOST);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	ft_putstr_fd("\033[?1049l", game->fd);
	return ;
}
