#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int sum = 0;
	int a;
	int b;
	int k;

	scanf_s("%d", &a);
	scanf_s("%d", &b);

	for (k = a; k <= b; k++)
	{
		sum = sum + k;
	}

	printf("%d���� %d���� ������ ���� %d�̴�.", a, b, sum);

	return 0;
}