#include "sort.h"

/**
 * swap_ints - In an array,it swaps two integers
 * @a: First integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - In an ascending order,it sort array of integers
 * @array: It sorts an array of integers
 * @size: The array size
 *
 * Description: After each swap it prints the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t e, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (e = 0; e < len - 1; e++)
		{
			if (array[e] > array[e + 1])
			{
				swap_ints(array + e, array + e + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
