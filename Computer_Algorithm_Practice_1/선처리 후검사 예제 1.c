#include <stdio.h>

void main()
{
	int sum = 0;
	int n = 1;

	do
	{
		sum = sum + n;
		n = n + 1;
	} while (n <= 10);
	{
		printf("%d\n", sum);
	}
}