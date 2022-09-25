#include <stdio.h>

void main()
{
	int sum = 0;
	int n = 1;

	while (1)
	{
		sum = sum + n;
		n = n + 1;

		if (n > 10)
		{
			break;
		}
	}
	printf("%d\n",sum);
}