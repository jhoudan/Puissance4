#include <puissance.h>

int		**fill_grid(int row, int column)
{
	int	**grid;
	int	i;

	grid = (int**)malloc(sizeof(int*) * row + 1);
	if (!grid)
		return (NULL);
	grid[row] = NULL;
	while (--row >= 0)
	{
		grid[row] = (int*)malloc(sizeof(int) * column);
		if (!grid[row])
			return (NULL);
		i = 0;
		while (i < column)
		{
			grid[row][i] = 0;
			i++;
		}
	}
	return (grid);
}

int		delete_grid(int **grid, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return (1);
}
