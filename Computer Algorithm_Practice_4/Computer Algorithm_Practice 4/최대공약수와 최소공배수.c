#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void main()
{
	int a = 0;
	int b = 0;
	int big = 0;
	int small = 0;
	int last = 0;
	int firstbig = 0;
	int firstsmall = 0;

	printf("���� 2���� �Է��Ͻÿ� : ");
	scanf_s("%d %d", &a, &b);

	if (a >= b)
	{
		firstbig=big = a;
		small=firstsmall = b;
	}
	else
	{
		big = firstbig=b;
		firstsmall=small = a;
	}

	while(1)
	{
		last = big % small;

		if (last == 0)
		{
			break;
		}
		else
		{
			big = small;
			small = last;
		}
	}

	printf("%d�� %d�� �ִ������� %d�Դϴ�.", firstbig, firstsmall, small);
	


}