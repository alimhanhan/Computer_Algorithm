#include <stdio.h>

int main()
{
	int a[5][5]; //2차원 배열
	int v = 0;    //배열 원소에 저장할 값
	int c = 0;  //열

	do
	{
		int r = 0;  //행
		do
		{
			v++;
			a[r][c] = v;
			r++;

		} while (r <= 4);  //열 우선 채우기

		c = c + 1;

	} while (c <= 4);

	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			printf("%d\t", a[r][c]);
		}

		printf("\n");
	}
}