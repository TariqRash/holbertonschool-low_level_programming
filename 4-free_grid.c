#include "main.h"

/**
 * free_grid - frees a 2D grid previously created by alloc_grid
 * @grid: the grid to free
 * @height: height of the grid
 *
 * Description: The cleanup crew! Frees memory like Marie Kondo
 * organizing a house - everything must go!
 *
 * Return: Nothing (void), but leaves behind a clean memory space
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
