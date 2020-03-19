// SPDX-License-Identifier: GPL-2.0-only
#include <stdio.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

typedef float datatype;

void swap(datatype *a, datatype *b)
{
#if 0
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
#else
	datatype temp = *a;
	*a = *b;
	*b = temp;
#endif
}

void bubble_sort(datatype *array, int size)
{
	int i;
	int j;

	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
		}
	}
}

void show_array(datatype *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%f ", array[i]);

	printf("\n");
}

int main(int argc, char *argv[])
{
	datatype array[] = { 17.5, 19.1, 0.6,  1.9,  10.5, 12.4, 3.8,
			     19.7, 1.5,	 25.4, 28.6, 4.4,  23.8, 5.4 };

	show_array(array, ARRAY_SIZE(array));
	bubble_sort(array, ARRAY_SIZE(array));
	show_array(array, ARRAY_SIZE(array));

	return 0;
}
