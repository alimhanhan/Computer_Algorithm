#include <stdio.h>

int main()
{
    int B[5][5] = { 0 };
    int row, col, cnt = 1;
    int index = 1;	//배열의 인덱스값을 나타내는 변수
    int k = 0;	//행, 열 변환을 위한 변수

    //대각선 - 우상향 배열 채우기
    while (1)
    {
        for (int col = 0; col < 5; col++)	//열 우선 채우기
        {
            for (int row = 0; row < 5; row++)
            {
                if (col + row == k)  //행 번호와 열 번호의 합이 변수 k의 값과 같다면 배열에 인덱스값 삽입
                {
                    B[row][col] = index;
                    index++;
                }
            }
        }

        k++;

        if (index > 25)		//인덱스의 크기가 25 초과라면 반복 종료
        {
            break;
        }
    }



    //대각선 - 좌하향 배열 채우기
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

    
   
    //완성된 배열 출력
    for (row = 0; row < 5; row++)
    {
        for (col = 0; col < 5; col++)
        {
            printf(" %d ", B[row][col]);
        }
        printf("\n");
    }
}