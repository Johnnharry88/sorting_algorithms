#include "sort.h"

/**
 * selection_sort - sorts all arrays using selection method
 * @array: array to be sorted
 * @size: size of array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	int idx, m, n;
	size_t x, y;

	if (array == NULL || size <= 1)
		return;
	for (x = 0; x < size - 1; x++)
	{
		m = array[x];
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < m)
			{
				m = array[y];
				idx = y;
			}
		}
		if (m != array[x])
		{
			n = array[x];
			array[x] = array[idx];
			array[idx] = n;
			print_array(array, size);
		}
	}
}
