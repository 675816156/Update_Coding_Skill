// C Program to find n'th fibonacci Number in
// with O(Log n) arithmatic operations
#include <stdio.h>

// Create an array for memoization
int f[1000] = { 0 };

// Returns n'th fuibonacci number using table f[]
int fib(int n)
{
	// Base cases
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return (f[n] = 1);

	// If fib(n) is already computed
	if (f[n])
		return f[n];

	int k = (n & 1) ? (n + 1) / 2 : n / 2;

	// Applying above formula [Note value n&1 is 1
	// if n is odd, else 0.
	f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1)) :
			 (2 * fib(k - 1) + fib(k)) * fib(k);

	return f[n];
}

/* Driver program to test above function */
int main(void)
{
	printf("%s %d\n", __FILE__, fib(45));
	return 0;
}