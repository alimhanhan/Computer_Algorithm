#include <stdio.h>

int main()
{
	int a[8];
	a[0] = '0'; a[1] = '1'; a[2] = '2'; a[3] = '3'; 
	a[4] = '4'; a[5] = '5'; a[6] = '6'; a[7] = '7';

	int b[20];

	int d = 0;  // 10진수 35
	int i = 0;
	int n = 0;
	int m = 0;

	printf("8진수로 변환할 10진수를 입력하시오. : ");
	scanf_s("%d", &d);

	printf("10진수 %d를 8진수로 변환한 값은 ", d);

	do {
		m = d / 8;  // 몫
		n = d % 8;  // 나머지
		
		b[i] = n;

		i++;
		d = m;

	} while (m >= 8);      // do-while 문에서 while 뒤에 꼭 세미콜론(;) 붙어야 함

	b[i] = m;

	for (int p = i; p >= 0; p--)
	{
		printf("%d",b[p]);
	}

	printf(" 입니다.");


	return 0;
}