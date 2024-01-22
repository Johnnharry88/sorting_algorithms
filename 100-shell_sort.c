#include "sort.h"

/**
 * shell_sort - sorts shell like obj
 * @array: array to be sorted
 * @size: sie of array
 * Return: void.
 */
void shell_sort(int *array, size_t size)
{
	size_t spx, x, y;
	int temp;

	spx = 1;
	if (!array || array == NULL || size < 2)
		return;
	while (spx < size / 3)
		spx = (1 + (spx *3));
	while (spx)
	{
		for (x = spx; x <size; x++)
		{
			temp = array[x];
			for (y = x; y >= spx && array[y- spx] > temp; y = y - spx)
				array[y] = array[y - spx];
			array[y] = temp;
		}
		print_array(array, size);
		spx = spx / 3;
	}
}


