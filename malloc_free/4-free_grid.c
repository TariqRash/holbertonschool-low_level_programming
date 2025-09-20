#include "main.h"

<<<<<<< HEAD
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
=======
>>>>>>> origin/main
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		return;
<<<<<<< HEAD

=======
>>>>>>> origin/main
	for (i = 0; i < height; i++)
	{
		if (grid[i] != NULL)
			free(grid[i]);
	}
<<<<<<< HEAD

=======
>>>>>>> origin/main
	free(grid);
}
