#include <stdio.h>

int main() 
{
    int C[5][5];
    int TEMP[5][5];  //배열의 좌측 회전 때 사용할 배열
    int index = 25;
    int a = 0; int b = 0;    //오른쪽, 왼쪽으로 이동하기 위한 변수
    int row = 0; int col = 0;   //배열의 행과 열을 나타내는 변수
    int i, k, j;
    int swich = 0;     //배열 좌우반전 시 사용할 스와핑 변수
    int way = 1;   //방향을 나타내는 방향변수 


    //딜팽이 모양으로 배열 채우기
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

        way = way * -1;   //변수 way의 부호를 바꾼다.

        for (k = 0; k < i; ++k) 
        {
            a += way;
            C[b][a] = index;
            index = index - 1;
        }
    }

    //배열 좌우반전
    for (row = 0; row < 5; row++)
    {
        for (col = 0; col < 3; col++)
        {
            swich = C[row][col];
            C[row][col] = C[row][4 - col];
            C[row][4 - col] = swich;
        }
    }


    //배열 좌측으로 90도 회전
    for (row = 0; row < 5; row++) 
    {
        for (col = 0; col < 5; col++) 
        {
            TEMP[4 - col][row] = C[row][col];
        }
    }


    //완성된 배열 출력
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
