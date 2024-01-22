#include "sort.h"

/**
 * array_part - partitions arrays
 * @array: Array to be sorted
 * @x: begining of the array
 * @y: end of array;
 * @size: array size in full
 * Return: Pivot point
 */
int array_part(int *array, int x, int y, int size)
{
	int xty = array[y];
	int a = x, b, tmp;

	for (b = a; b < y; b++)
	{
		if (array[b] <= xty)
		{
			if (a != b)
			{
				tmp = array[a];
				array[b] = array[a];
				array[b] = tmp;
				print_array(array, size);
			}
			a = a + 1;
		}
	}
	if (a != y)
	{
		tmp = array[a];
		array[a] = array[y];
		array[y] = tmp;
		print_array(array, size);
	}
	return (a);
}

/**
 * sort_quick - sorts items recursively
 * @array: array to be sorted.
 * @x: begining of an array
 * @y: end of the array
 * @size: size of array in full
 * Return: void.
 */
void sort_quick(int *array, int x, int y, int size)
{
	int alx;

	if (x < y)
	{
		alx = array_part(array, x, y, size);
		sort_quick(array, x, alx - 1, size);
		sort_quick(array, alx + 1, y, size);
	}
}

/**
 * quick_sort - sorts an array
 * @array: arrau to be sorted.
 * @size: Size of array in full
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || !array || size < 2)
		return;
	sort_quick(array, 0, size - 1, size);
}
