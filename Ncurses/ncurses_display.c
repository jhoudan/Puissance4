#include <curses.h>
#include <assert.h>
#include "puissance.h"

static void		put_circle(int x, int y, int identifier)
{
	wattron(stdscr, COLOR_PAIR(identifier)); 
	mvaddstr(x - 1, y - 2, " /|\\ ");
	mvaddstr(x, y - 2, "|||||");
	mvaddstr(x + 1, y - 2, " \\|/ ");
	wattroff(stdscr, COLOR_PAIR(identifier));
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
				put_circle(((row / game->line) * x + (row / game->line) *
							(x - 1)) / 2, ((col / game->column) * y + 
							(col / game->column) * (y - 1)) / 2,
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

static void	draw_grid_ncurses(t_game *game)
{
	int row;
	int col;
	int x;
	int i;

	clear();
	start_color();
	getmaxyx(stdscr, row, col);
	col = col > 222 ? 222 : col;
	init_color(COLOR_WHITE, 500, 500, 500);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	wattron(stdscr, COLOR_PAIR(3));
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
	wattroff(stdscr, COLOR_PAIR(3));
	put_vals(game, row, col);
	refresh();
}

static void	put_mouse_value(int column, t_game *game)
{
	int row;
	int col;

	getmaxyx(stdscr, row, col);
	col = col > 222 ? 222 : col;
	if (column % (col / game->column) != 0)
	{
		mvprintw(0, 0, "%d", column);
		if (column > (col / game->column))
			put_in_grid(game, column / (col / game->column), 1);
		else
			put_in_grid(game, 0, 1);
		put_vals(game, row, col);
	}

}

static void check_scr_size(t_game *game)
{
	int row;
	int col;

	getmaxyx(stdscr, row, col);
	if (((game->line * 4) + 1) > row || ((game->column * 6) + 1) > col)
	{
		clear();
		mvaddstr(0, 0, "Window too small, please make it bigger to continue");
		refresh();
	}
	else
	{
		draw_grid_ncurses(game);
	}
}

static void	key_manager(int key, t_game *game)
{
	MEVENT	event;
	if (key == KEY_RESIZE)
		check_scr_size(game);
	if (key == KEY_MOUSE)
	{
		assert(getmouse(&event) == OK);
		if (event.bstate == 4)
			put_mouse_value(event.x, game);
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
	check_scr_size(game);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	while((ch = getch()) != 27)
		key_manager(ch, game);
	endwin();
}



