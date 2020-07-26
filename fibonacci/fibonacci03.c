#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fibonacci01(int n)
{
	int i, a, b;

	if (n < 1)
		return -1;

	if (n == 1 || n == 2)
		return 1;

	a = b = 1;

	for (i = 3; i <= n; ++i) {
		b = a + b;
		a = b - a;
	}
	return b;
}

void main(void)
{
	int ret;
	ret = fibonacci01(45);

	printf("fibonacci03 result: %d\n", ret);
}
