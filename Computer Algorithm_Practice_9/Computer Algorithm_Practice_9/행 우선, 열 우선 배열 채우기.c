#include <stdio.h>

int main()
{
	int a[5][5]; //2���� �迭
	int v = 0;    //�迭 ���ҿ� ������ ��
	int c = 0;  //��

	do
	{
		int r = 0;  //��
		do
		{
			v++;
			a[r][c] = v;
			r++;

		} while (r <= 4);  //�� �켱 ä���

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