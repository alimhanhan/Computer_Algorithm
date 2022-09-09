#include <stdio.h>

int main()
{
	int num[5] = { 70,60,50,80,90 };
	int min = 9999;
	int n=0;

	for (n = 0; n < 5; n++)
	{
		if (min > num[n])
		{
			min = num[n];
		}
	}
	printf("배열 num의 원소들 중 최솟값은 %d이다.", min);

	return 0;
}