#include <stdio.h>

int main() 
{
    int C[5][5];
    int TEMP[5][5];  //�迭�� ���� ȸ�� �� ����� �迭
    int index = 25;
    int a = 0; int b = 0;    //������, �������� �̵��ϱ� ���� ����
    int row = 0; int col = 0;   //�迭�� ��� ���� ��Ÿ���� ����
    int i, k, j;
    int swich = 0;     //�迭 �¿���� �� ����� ������ ����
    int way = 1;   //������ ��Ÿ���� ���⺯�� 


    //������ ������� �迭 ä���
    for (k = 0; k < 5; ++k) 
    {
        C[b][a] = index;
        index = index - 1;
        a += way;
    }

    a = a - 1;

    for (i = 4; i > 0; --i) 
    {
        for (j = 0; j < i; ++j) 
        {
            b += way;
            C[b][a] = index;
            index = index - 1;
        }

        way = way * -1;   //���� way�� ��ȣ�� �ٲ۴�.

        for (k = 0; k < i; ++k) 
        {
            a += way;
            C[b][a] = index;
            index = index - 1;
        }
    }

    //�迭 �¿����
    for (row = 0; row < 5; row++)
    {
        for (col = 0; col < 3; col++)
        {
            swich = C[row][col];
            C[row][col] = C[row][4 - col];
            C[row][4 - col] = swich;
        }
    }


    //�迭 �������� 90�� ȸ��
    for (row = 0; row < 5; row++) 
    {
        for (col = 0; col < 5; col++) 
        {
            TEMP[4 - col][row] = C[row][col];
        }
    }


    //�ϼ��� �迭 ���
    for (row = 0; row < 5; row++) 
    {
        for (col = 0; col < 5; col++) 
        {
            printf("   %d   ", TEMP[row][col]);
        }

        printf("\n");
    }

    return 0;
}
