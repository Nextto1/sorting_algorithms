#include "sort.h"

/**
 * swap_ints - It swaps two integers in the array.
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
 * lomuto_partition - In an order of subset of the array of the
 * integers by the lomuto partition scheme.
 * @array: Array of integers for the function
 * @size: Size of the array for the function
 * @left: The subset to order start index.
 * @right: The subset to order end index.
 *
 * Return: The partition index finally for the function
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *center, high, low;

	center = array + right;
	for (high = low = left; low < right; low++)
	{
		if (array[low] < *center)
		{
			if (high < low)
			{
				swap_ints(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}

	if (array[high] > *center)
	{
		swap_ints(array + high, center);
		print_array(array, size);
	}

	return (high);
}

/**
 * lomuto_sort - Utilizing the quicksort algorithm
 * @array: Array to sort of integers for the function
 * @size: Size of the array for the function
 * @left: The array partition start index to order
 * @right: The array partition end index to order
 *
 * Description: Using the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int half;

	if (right - left > 0)
	{
		half = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, half - 1);
		lomuto_sort(array, size, half + 1, right);
	}
}

/**
 * quick_sort - It sorts an array of integers in ascending
 * using the correct algorithm
 * @array: Array of integers for the function
 * @size: Size of the array for the function
 *
 * Description: Using the Lomuto partition scheme
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
