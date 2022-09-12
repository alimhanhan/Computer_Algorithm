#include <stdio.h>

int factorial(int n)
{
	int fact = 1;

	if (n > 0)
	{
		fact = n * factorial(n - 1);
		return fact;
	}
}

void main()
{
	int n;
	int fact;

	scanf_s("%d",&n);
	printf("%d", n);

	fact = factorial(n);
	printf("의 누승은 %d입니다.",fact);
}