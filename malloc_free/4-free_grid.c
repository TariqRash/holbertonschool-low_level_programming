#include "main.h"

/**
 * free_grid - frees a 2 dimensional grid previously created by alloc_grid
 * @grid: the grid to free
 * @height: height of the grid
 *
 * Description: This function frees a 2D grid previously created by
 * the alloc_grid function. Note that we will compile with your
 * alloc_grid.c file. Make sure it compiles.
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		return;

	for (i = 0; i < height; i++)
	{
		if (grid[i] != NULL)
			free(grid[i]);
	}

	free(grid);
}
