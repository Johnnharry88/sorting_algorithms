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
 * merge - function that merges
 * @temp: stores temporary data
 * @aarray: standing in form start to middle
 * @x: first position of element in array
 * @y: Middle position of array
 * @z: last position of array
 * Return: void
 */
void merge(int *aarray, int *temp, int x, int y, int z)
{
	int a = y - x + 1, b = z - y;
	int *l_array, *r_array, i, j, alx = 0;

	l_array = &temp[alx];
	r_array = &temp[b];
	for (i = 0; i < a; i++)
		l_array[i] = aarray[x + i];
	for (j = 0; j < b; j++)
		r_array[j] = aarray[j + 1 + y];
	i = 0;
	j = 0, alx = x;
	while (i < a && j < b)
	{
		if (l_array[i] <= r_array[j])
		{
			aarray[alx] = l_array[i];
			i = i + 1;
		}
		else
		{
			aarray[alx] = r_array[j];
			j = j + 1;
		}
		alx = alx + 1;
	}
	while (i < a)
		aarray[alx] = l_array[i], i++, alx++;
	while (j < b)
		aarray[alx] = r_array[j], j++, alx++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l_array, i);
	printf("[right]: ");
	print_array(r_array, j);
	printf("[Done]: ");
	print_array(&aarray[x], i + j);
}

/**
 * sort_array - function that sorts out aray of integers
 * @array: array of integers to be sorted
 * @temp: array used for merge purposes
 * @x: first postion of element in array
 * @z: last position of element in array
 * Return: void
 */
void sort_array(int *array, int *temp, int x, int z)
{
	int c;

	c = (x + z) / 2;
	if ((x + z) % 2 == 0)
		c = c - 1;
	if (c >= x)
	{
		sort_array(array, temp, x, c);
		sort_array(array, temp, c + 1, z);
		merge(array, temp, x, c, z);
	}
}

/**
 * merge_sort - function that sorts array of integers
 * @size: size of the array
 * @array: array of integers
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size <= 1)
		return;
	temp = _calloc(size, sizeof(int));
	sort_array(array, temp, 0, size - 1);
	free(temp);
}
