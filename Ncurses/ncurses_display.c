#include "puissance.h"

static void		put_circle(int x, int y, int identifier)
{
	wattron(stdscr, COLOR_PAIR(identifier)); 
	mvaddstr(x - 1, y - 2, " /|\\ ");
	mvaddstr(x, y - 2, "|||||");
	mvaddstr(x + 1, y - 2, " \\|/ ");
	wattroff(stdscr, COLOR_PAIR(identifier));
}

static void		put_vals(t_game *game)
{
	int	x;
	int	y;
	int row;
	int col;

	getmaxyx(stdscr, row, col);
	col = col > 222 ? 222 : col;
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
	put_vals(game);
	refresh();
}

static int	put_mouse_value(int column, t_game *game, int id)
{
	int row;
	int col;

	getmaxyx(stdscr, row, col);
	col = col > 222 ? 222 : col;
	if (column % (col / game->column) != 0)
	{
		if (column > (col / game->column))
			put_in_grid(game, column / (col / game->column), id);
		else
			put_in_grid(game, 0, id);
		put_vals(game);
		return (column / (col / game->column));
	}
	return (-1);
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

static int	key_manager(int key, t_game *game)
{
	int input;
	int id;

	if (game->ia == 1)
		id = 2;
	else
		id = 1;
	MEVENT	event;
	if (key == KEY_RESIZE)
	{
		check_scr_size(game);
		return (3);
	}
	if (key == KEY_MOUSE)
	{
		assert(getmouse(&event) == OK);
		if (event.bstate == 4)
		{
			input = put_mouse_value(event.x, game, id);
			if (input == -1)
				return (3);
			if (check_if_win(game, input, id) == 1)
				return (1);
		}
	}
	return(0);
}

static int ia_turn_ncurse(t_game *game)
{
	int		input;

	input = get_column_to_play(game);
	put_in_grid(game, input, game->ia);
	if (check_if_win(game, input, game->ia) == 1)
		return (2);
	put_vals(game);
	return (0);
}

void	ncurses_init(t_game *game)
{
	int ch;
	int i;
	int max;
	int win;

	i = -1;
	max = game->column * game->line;
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	check_scr_size(game);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	if (game->ia == 1)
		ia_turn_ncurse(game);
	while((ch = getch()) != 27 && ++i < max)
	{
		win = key_manager(ch, game);
		put_vals(game);
		if (win == 1)
			break ;
		if (win != 3)
		{
			if (ia_turn_ncurse(game) == 2)
			{
				win = 2;
				break ;
			}
		}
	}
	endwin();
	draw_grid(game);
}



