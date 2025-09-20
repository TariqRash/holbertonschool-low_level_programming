#include "main.h"

<<<<<<< HEAD
/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Description: Each element of the grid should be initialized to 0.
 * The function should return NULL on failure. If width or height is
 * 0 or negative, return NULL.
 *
 * Return: pointer to 2D array, or NULL on failure
 */
=======
>>>>>>> origin/main
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);
<<<<<<< HEAD

	grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);

=======
	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
>>>>>>> origin/main
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}
<<<<<<< HEAD

		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

=======
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}
>>>>>>> origin/main
	return (grid);
}
