// Fn = { [(√5 + 1) / 2] ^ n } / √5

// C Program to find n'th fibonacci Number
#include <stdio.h>
#include <math.h>

int fib(int n)
{
	double phi = (1 + sqrt(5)) / 2;
	return round(pow(phi, n) / sqrt(5));
}

int main()
{
	printf("%s %d\n", __FILE__, fib(45));
	return 0;
}