#include "sort.h"

/**
 * _xchange - swaps position of two welements
 * @array : Array to be sorted
 * @x: first array element.
 * @y: second array element
 * Return: void.
 */
void _xchange(int *array, size_t x, size_t y)
{
	int temp;

	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

/**
 * array_part - partitions arrays
 * @array: Array to be sorted
 * @x: begining of the array
 * @y: end of array;
 * @size: array size in full
 * Return: Pivot point
 */
int array_part(int *array, int x, int y, size_t size)
{
	int a, xty, b, temp;

	xty = array[y];
	a = x;
	for (b = x; b <= y - 1; b++)
	{
		if (array[b] < xty)
		{
			temp = array[a];
			array[a] = array[b];
			array[b] = temp;
			if (array[a] != array[b]
				print_array(array, size);
			a = a + 1;
		}
	}
	temp = array[a];
	array[a] = array[y];
	array[y] = temp;
	if (array[a] != array[y])
		print_array(array, size);
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
void sort_quick(int *array, size_t size, int x, int y)
{
	int alx;

	if (x < y)
	{
		alx = array_part(array, x, y, size);
		sort_quick(array, x, alx - 1, size);
		sort_quick(array,alx + 1, y, size);
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
	sort_quick(array, 0, (int)size - 1, size);
}
