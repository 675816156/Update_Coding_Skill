#include <stdio.h>
#include <stdlib.h>

int fibonacci01(int n)
{
	if (n < 1)
		return -1;
	if (n == 1 || n == 2)
		return 1;
	return fibonacci01(n - 1) + fibonacci01(n - 2);
}

void main(void)
{
	int ret;
	ret = fibonacci01(45);

	printf("fibonacci01 result: %d\n", ret);
}
