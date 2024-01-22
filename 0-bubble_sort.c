#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts array elements and prints them using
 * buble sort.
 * @array: array to swap
 * @size: Size of an array
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, n_size = size;
	int tmp, flag;

	if (!array || array == NULL || size < 2)
		return;
	while (n_size)
	{
		flag = 0;
		for (x = 0; x < n_size - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				flag = 1;
				tmp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = tmp;
				print_array(array, size);
			}
		}
		n_size = n_size - 1;
		if (!flag)
			break;
	}
}
