#include "sort.h"
#include <stdio.h>

/**
 * _calloc - the function that alllocates storage for aray of number
 * @n_x: Numbr of elements
 * @size: size of each element
 * Return: pointer to new assigned memory
 */
void *_calloc(unsigned int n_x, unsigned int size)
{
	unsigned int a = 0;
	char *alx;

	if (n_x == 0 || size == 0)
		return (NULL);
	alx = malloc(n_x * size);
	if (alx == NULL)
		return (NULL);
	for (a = 0; a < (n_x * size); a++)
		alx[a] = '\0';
	return (alx);
}

/**
 * counting_sort - function that sorts arrays in ascending order
 * @array: array to be sorted.
 * @size: size of the asrray to be sorted
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int idx, max = 0;
	int *count = '\0', *temp = '\0';
	size_t x;

	if (array == NULL || size < 2)
		return;
	for (x = 0; x < size; x++)
		if (array[x] > max)
			max = array[x];
	count = _calloc(max + 1, sizeof(int));
	temp = _calloc(size + 1, sizeof(int));
	for (x = 0; x < size; x++)
		count[array[x]]++;
	for (idx = 1; idx <= max; idx++)
		count[idx] = count[idx] + count[idx - 1];
	print_array(count, max + 1);
	for (x = 0; x < size; ++x)
	{
		temp[count[array[x]] - 1] = array[x];
		count[array[x]]--;
	}
	for (x = 0; x < size; x++)
		array[x] = temp[x];
	free(temp);
	free(count);
}
