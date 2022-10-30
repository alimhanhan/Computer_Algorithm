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

	printf("정수 2개를 입력하시오 : ");
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

	printf("%d와 %d의 최대공약수는 %d입니다.", firstbig, firstsmall, small);
	


}