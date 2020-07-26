#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fibonacci01(int n)
{
	int i;
	int *a = (int *)malloc(n);

	memset(a, 0, sizeof(int) * n);

	if (n < 1)
		return -1;

	a[1] = 1;
	a[2] = 1;

	for (i = 3; i <= n; ++i)
		a[i] = a[i - 1] + a[i - 2];

	return a[n];
}

void main(void)
{
	int ret;
	ret = fibonacci01(45);

	printf("fibonacci02 result: %d\n", ret);
}
