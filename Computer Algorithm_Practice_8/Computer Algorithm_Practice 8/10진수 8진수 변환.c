#include <stdio.h>

int main()
{
	int a[8];
	a[0] = '0'; a[1] = '1'; a[2] = '2'; a[3] = '3'; 
	a[4] = '4'; a[5] = '5'; a[6] = '6'; a[7] = '7';

	int b[20];

	int d = 0;  // 10���� 35
	int i = 0;
	int n = 0;
	int m = 0;

	printf("8������ ��ȯ�� 10������ �Է��Ͻÿ�. : ");
	scanf_s("%d", &d);

	printf("10���� %d�� 8������ ��ȯ�� ���� ", d);

	do {
		m = d / 8;  // ��
		n = d % 8;  // ������
		
		b[i] = n;

		i++;
		d = m;

	} while (m >= 8);      // do-while ������ while �ڿ� �� �����ݷ�(;) �پ�� ��

	b[i] = m;

	for (int p = i; p >= 0; p--)
	{
		printf("%d",b[p]);
	}

	printf(" �Դϴ�.");


	return 0;
}