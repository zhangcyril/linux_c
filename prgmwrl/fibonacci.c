#include <stdio.h>
#include <math.h>

long int fibonacci(long int n);

int main(void)
{
	int n;
	long int res;
	printf("u want to get  NO.x of the Fibonacci?");
	scanf("%d", &n);

	res = fibonacci(n);
	printf("\nNo.%d of the fibonacci is %li\n", n, res);

	return 0;
}

long int fibonacci(long int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;

	return (fibonacci(n - 1) + fibonacci(n - 2));

}
