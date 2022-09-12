#include <stdio.h>

int fact()
{
	int k;
	scanf_s("%d",&k);

	int result = 1;

	if (k >= 0)
	{
		for (int i = 0; i < k; i++)
		{
			result = result * (k-i);
		}
	}

	printf("%d!의 값은 %d입니다.", k,result);
	return result;
}

int main()
{
	fact();

	return 0;
}