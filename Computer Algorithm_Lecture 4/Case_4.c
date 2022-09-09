#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int k;
	int total = 1;

	scanf_s("%d",&k);

	if (k >= 0)
	{
		for(int i=0; i<k;i++)
		{
			total = total * (k - i);
		}
	}
	else
	{
		printf("입력된 정수는 0이상이여야 합니다.");
	}

	printf("%d!의 값은 %d입니다.", k,total);

	return 0;
}