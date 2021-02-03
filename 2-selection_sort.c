#include "sort.h"

/**
 * selection_sort - sort array using selection sort algorithm
 * @array: array
 * @size: array size
 **/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min, temporal;

	if (array == NULL || size < 2)
		return;

	/*  0   1   2   3   4   5   6   7   8   9 */
	/* {19, 48, 99, 71, 13, 52, 96, 73, 86, 7}; */

	for (i = 0; i < size; i++)
	{
		/* min = 3; array[min] = 99 */

		min = i;
		for (j = i + 1; j < size; j++)
		{
			/* j = 4; array[j] = 13 */

			/* si 99 > 13? */
			if (array[min] > array[j])
				/* Entonces min ahora vale 4 */
				min = j;
		}

		/* si min (4) es distinto 3? */
		if (min != i)
		{
			/* Entonces array[min] (13) */
			temporal = array[min];
			/* Array[min] (13) > array[i] = 99 */
			array[min] = array[i];
			/* array[i] = 13 */
			array[i] = temporal;

			/*  0   1   2   3   4   5   6   7   8   9 */
			/* {19, 48, 71, 13, 99, 52, 96, 73, 86, 7}; */

			print_array(array, size);
		}
	}
}
