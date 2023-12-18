#include "sort.h"

/**
 * swap_ints - In an array,it swaps two integers
 * @a: First integer to swap in the function
 * @b: Second integer to swap in the function
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - In ascending order,sort an array of integers
 * using the correct algorithm.
 * @array: An integers array
 * @size: The array size
 *
 * Description: It prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *mint;
	size_t e, k;

	if (array == NULL || size < 2)
		return;

	for (e = 0; e < size - 1; e++)
	{
		mint = array + e;
		for (k = e + 1; k < size; k++)
			mint = (array[k] < *mint) ? (array + k) : mint;

		if ((array + e) != mint)
		{
			swap_ints(array + e, mint);
			print_array(array, size);
		}
	}
}
