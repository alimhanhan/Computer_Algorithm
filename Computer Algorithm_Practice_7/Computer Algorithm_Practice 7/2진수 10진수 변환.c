#include <stdio.h>
#include <math.h>

int main()
{
	int a[8] = { 1,1,1,1,1,0,0,0 };
	int q = 0;

	for (int i = 7; i>=1; i--)
	{
		int k = (int)pow(2, 7 - i);
		q += k * a[i];
	}

	printf("%d\n", q);

	int m = 128 - q;

	if (a[0] == 1)
	{
		printf("%d",m *= -1);
	}
	else
	{
		printf("%d",m);
	}

	return 0;
}