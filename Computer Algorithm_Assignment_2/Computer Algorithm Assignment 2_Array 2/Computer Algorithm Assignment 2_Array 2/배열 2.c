#include <stdio.h>

int main()
{
    int B[5][5] = { 0 };
    int row, col, cnt = 1;
    int index = 1;	//�迭�� �ε������� ��Ÿ���� ����
    int k = 0;	//��, �� ��ȯ�� ���� ����

    //�밢�� - ����� �迭 ä���
    while (1)
    {
        for (int col = 0; col < 5; col++)	//�� �켱 ä���
        {
            for (int row = 0; row < 5; row++)
            {
                if (col + row == k)  //�� ��ȣ�� �� ��ȣ�� ���� ���� k�� ���� ���ٸ� �迭�� �ε����� ����
                {
                    B[row][col] = index;
                    index++;
                }
            }
        }

        k++;

        if (index > 25)		//�ε����� ũ�Ⱑ 25 �ʰ���� �ݺ� ����
        {
            break;
        }
    }



    //�밢�� - ������ �迭 ä���
    for (row = 0; row < 5; row=row+2)
    {
        for (col = 0; col <= row; col++)
        {
            B[col][row - col] = cnt;
            cnt++;
        }

        cnt=cnt+row+2;
    }

    cnt = 20;
    for (row = 2; row < 5; row=row+2)
    {
        for (col = row; col < 5; col++)
        {
            B[col][row - col + 4 ] = cnt;
            cnt++;
        }

        cnt = cnt + row;
    }

    
   
    //�ϼ��� �迭 ���
    for (row = 0; row < 5; row++)
    {
        for (col = 0; col < 5; col++)
        {
            printf(" %d ", B[row][col]);
        }
        printf("\n");
    }
}