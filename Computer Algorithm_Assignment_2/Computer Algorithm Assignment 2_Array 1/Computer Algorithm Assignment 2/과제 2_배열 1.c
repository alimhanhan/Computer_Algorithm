#include<stdio.h>

int main() 
{
	int A[5][5];
	int index = 1;	//�迭�� �ε������� ��Ÿ���� ����
	int k = 0;	//��, �� ��ȯ�� ���� ����

	while(1)
	{
		for (int col = 0; col < 5; col++)	//�� �켱 ä���
		{
			for (int row = 0; row < 5; row++)
			{
				if (col + row == k)  //�� ��ȣ�� �� ��ȣ�� ���� ���� k�� ���� ���ٸ� �迭�� �ε����� ����
				{
					A[row][col] = index;
					index++;
				}
			}
		}

		k++;

		if (index > 25 )		//�ε����� ũ�Ⱑ 25 �ʰ���� �ݺ� ����
		{
			break;
		}
	}


	//�ϼ��� �迭 ���
	for (int row = 0; row < 5; row++)	//�� �켱 ���
	{
		for (int col = 0; col < 5; col++)
		{
			printf(" %d ", A[row][col]);
		}
		
		printf("\n");
	}

	return 0;
}