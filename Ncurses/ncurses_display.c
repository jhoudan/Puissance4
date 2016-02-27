#include <curses.h>
#include <assert.h>
#include "puissance.h"

static void		put_circle(int x, int y, int identifier)
{
	mvprintw(x, y, "%d", identifier);
}

static void		put_vals(t_game *game, int row, int col)
{
	int	x;
	int	y;

	x = game->line;
	while (x > 0)
	{
		y = game->column;
		while (y > 0)
		{
			if (game->grid[x - 1][y - 1] != 0)
				put_circle(((row / game->line) * x + (row / game->line) * x - 1)
						/ 2, ((col / game->column) * y + 
							(col / game->column) * y - 1) / 2,
						game->grid[x -1][y - 1]);
						y--;
		}
		x--;
	}
}

static int		*createtab(int xa, int ya, int xb, int yb)
{
	int			*tab;

	tab = (int *)malloc(sizeof(int) * 4);
	tab[0] = xa;
	tab[1] = ya;
	tab[2] = xb;
	tab[3] = yb;
	return (tab);
}

static void		drawline(int *t, char ch)
{
	int i;

	i = 0;
	if (t[0] == t[2])
	{
		while (t[1] + i < t[3])
		{
				mvaddch(t[0], t[1] + i, ch);
			i++;
		}
	}
	else
	{
		while (t[0] + i < t[2])
		{
				mvaddch(t[0] + i, t[1], ch);
			i++;
		}
	}
	free(t);
}

static void	draw_grid_2(t_game *game)
{
	int row;
	int col;
	int x;
	int i;

	clear();
	start_color();
	getmaxyx(stdscr, row, col);

	if (game->line > row)
		ft_putendl("ok");
	if (game->column > col)
		ft_putendl("ok");
 
	init_color(COLOR_WHITE, 500, 500, 500);
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	wattron(stdscr, COLOR_PAIR(1));
	x = 0;
	while (x <= game->column)
	{
		i = (col / game->column) * x;
		drawline(createtab(0, i, (row / game->line) * game->line + 1, i), ' ');
		x++;
	}
	x = 0;
	while (x <= game->line)
	{
		i = (row / game->line) * x;
		drawline(createtab(i, 0, i, (col / game->column) * game->column), ' ');
		x++;
	}
	/*drawline(createtab(0, 0, 0, col), '-');
	drawline(createtab(0, col - 1, row, col - 1), '|');
	drawline(createtab(row - 1, 0, row - 1, col), '-');*/
	wattroff(stdscr, COLOR_PAIR(1));
	put_vals(game, row, col);
	refresh();
}

/*void mouse_click(t_game *game)
{
	MEVENT	event;
	assert(getmouse(&event) == OK);

}*/

static void	key_manager(int key, t_game *game)
{
	MEVENT	event;
	if (key == KEY_RESIZE)
		draw_grid_2(game);
	if (key == KEY_MOUSE)
	{
		assert(getmouse(&event) == OK);
		clear();
		mvprintw(0, 0, "%x", event.bstate);
		refresh();
	}


}

void	ncurses_init(t_game *game)
{
	int ch;
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	game->grid[0][0] = 2;
	game->grid[0][1] = 1;
	draw_grid_2(game);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	while((ch = getch()) != 27)
		key_manager(ch, game);
	endwin();
}



