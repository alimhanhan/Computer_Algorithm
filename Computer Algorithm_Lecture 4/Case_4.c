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
		printf("�Էµ� ������ 0�̻��̿��� �մϴ�.");
	}

	printf("%d!�� ���� %d�Դϴ�.", k,total);

	return 0;
}