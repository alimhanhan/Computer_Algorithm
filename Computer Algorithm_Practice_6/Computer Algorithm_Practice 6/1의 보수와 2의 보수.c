#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int a[5] = { 0,1,0,1,0 };
	int b[5];
	int t[5];
	int i = 0;

	do {
		b[i] = 1 - a[i];
		i++;
	} while (i < 5);

	i = 4;
	int c = 1;

	do {
		t[i] = 1;

		if (b[i] == c)
		{
			t[i] = 0;
		}

		c = b[i] * c;
		i--;
	} while (i >= 0);

	for (int k = 0; k < 5; k++)
	{
		printf("%d", t[k]);
	}


	return 0;
}