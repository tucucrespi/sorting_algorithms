#include "sort.h"

/**
 * _split - Split the array and takes the last element as pivot
 * @array: Array
 * @first: first element of array
 * @last: last element of array
 * @size: size of array
 * Return: index of new part
 **/
int _split(int *array, int first, int last, size_t size)
{
	int pivot;
	int i = first;
	int j, temp;

	pivot = array[last];
	for (j = first; j < last; j++)
	{
		if (array[j] <= pivot)
		{

			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			if (i != j)
				print_array(array, size);
			i++;

		}
	}

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	if (i != j)
		print_array(array, size);

	return (i);
}

/**
 * quick_sort_parts - sort array in two parts
 * @array: array
 * @first: first index
 * @last: last index
 * @size: size of array
 * Return: Nothing
 */
void quick_sort_parts(int *array, int first, int last, size_t size)
{

	int pivot;

	if (first < last)
	{
		pivot = _split(array, first, last, size);
		quick_sort_parts(array, first, (pivot - 1), size);
		quick_sort_parts(array, (pivot + 1), last, size);
	}
}

/**
 * quick_sort -Sort an array using quick_sort algorithm
 * @array: array to be sorted
 * @size: size of array
 **/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_parts(array, 0, size - 1, size);
}
