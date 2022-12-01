#include<stdio.h>

int main() 
{
	int A[5][5];
	int index = 1;	//배열의 인덱스값을 나타내는 변수
	int k = 0;	//행, 열 변환을 위한 변수

	while(1)
	{
		for (int col = 0; col < 5; col++)	//열 우선 채우기
		{
			for (int row = 0; row < 5; row++)
			{
				if (col + row == k)  //행 번호와 열 번호의 합이 변수 k의 값과 같다면 배열에 인덱스값 삽입
				{
					A[row][col] = index;
					index++;
				}
			}
		}

		k++;

		if (index > 25 )		//인덱스의 크기가 25 초과라면 반복 종료
		{
			break;
		}
	}


	//완성된 배열 출력
	for (int row = 0; row < 5; row++)	//행 우선 출력
	{
		for (int col = 0; col < 5; col++)
		{
			printf(" %d ", A[row][col]);
		}
		
		printf("\n");
	}

	return 0;
}