#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int a[10] = { 100, 39,24,400,5,77,457,3,22,830 };
	int chai = 0;
	int firstchai = a[0] - 33;
	int num = 0;

	for (int i = 0; i < 10; i++)
	{
		if (a[i] >= 33)
		{
			chai = a[i] - 33;
		}
		else
		{
			chai = 33 - a[i];
		}

		if (chai >= firstchai)
		{
			chai = chai;
		}
		else
		{
			firstchai = chai;
			num = i;
		}
	}

	printf("정수 33에 가장 가까운 근사값을 가진 원소는 배열의 %d번째 항이다.",num+1);
	return 0;
}