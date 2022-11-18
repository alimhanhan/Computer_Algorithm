#include <stdio.h>
#include <math.h>
#include <limits.h>

int binary[31];			//2진수로 변환된 값이 저장될 배열
int userget = 0;		//사용자로부터 입력받는 정수
char h[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };   //16진수에서 나타날 수 있는 숫자를 문자형으로 저장하고 있는 배열
char h16[32];  //16진수로 변환된 값이 저장될 배열
char hfinal[32];    //최종적으로 변환된 16진수 값이 저장될 배열 -> 사용자로부터 입력받은 값이 음수일 경우에만 사용
int hex16[32];    //1의 보수와 2의 보수를 구하는 과정에서 쓰일 배열
int h8[32];    //받아들인 10진수 양수 --> 8진수로 변환된 값이 저장될 배열
int octal[32];  //받아들인 10진수 음수 --> 8진수 과정에서만 사용
				//8진수로 변환된 값이 저장될 배열


int main() 
{	
	//사용자로부터 정수 입력받기
	printf("정수를 입력하시오 : ");   
	scanf_s("%d", &userget);

	//원래 입력값 보존을 위한 별도 변수 정의
	int fix2 = userget;       //10 -> 2진수 때 사용
	int userget16 = userget;  //10 -> 16진수 때 사용
	int fix8 = userget;       //10 -> 8진수 때 사용

	//입력받은 양수 10진수 --> 2진수
	if (fix2 >= 0)   
	{
		int i = 0;     //이진수 출력을 위한 변수 i

		while (fix2 > 0)
		{
			binary[i] = fix2 % 2;  //배열 binary에 fix2를 2로 나눈 나머지 저장
			fix2 = fix2 / 2;    //fix2를 2로 나눈 몫이 새로운 fix2가 됨
			i++;    
		}

		//변환한 2진수값 출력
		printf("2진수 : ");
		for (int kor=i; kor >= 0; kor--)
		{
			printf("%d", binary[kor]);
		}

	}

	//입력받은 음수 10진수 --> 2진수
	else      
	{
		int i = 0;       //이진수 출력을 위한 변수 i

		fix2 = fix2 + 1;
		fix2 = fix2 * -1;   //입력받은 음수의 절댓값 구하기

		while (fix2 > 0)    //절댓값을 이진수로 변환
		{
			binary[i] = fix2 % 2;
			fix2 = fix2 / 2;
			i++;
		}
		int kor = i;

		printf("2진수 : ");
		for (kor = i; kor >= 0; kor--)
		{
			printf("%d", !(binary[kor]));    //! 연산자를 사용하여 비트 반전시켜 출력
		}

	}

	printf("\n");		//줄 바꿈

	//입력받은 음수 10진수 --> 16진수
	if (userget16 < 0)      
	{
		userget16 = userget16 * -1;  //입력받은 10진수 음수의 절댓값 구하기
		int i = 0;
		
		while (i<=12)    //절댓값을 이진수로 변환
		{
			if (userget16 > 0)
			{
				hex16[i] = userget16 % 2;
				userget16 = userget16 / 2;
				i++;
			}
			else
			{
				hex16[i] = 0;
				i++;
			}
			
		}
		int ex = i;
		
		for (int s =0; s <ex; s++)      //hex16[] 에 대한 1의 보수 구하기
		{
			if (hex16[s] == 1)
			{
				hex16[s] = 0;
			}
			else
			{
				hex16[s] = 1;
			}
		}
		
		int save = ex;
		
		if (hex16[0] == 0 && hex16[1] == 0)        //hex16[]에 대한 2의 보수 구하기(이진수 덧셈 => 십진수 1, 즉 이진수 01 을 더하기)
		{
			hex16[0] = 1; hex16[1] = 0;
		}
		else if (hex16[0] == 0 && hex16[1] == 1)
		{
			hex16[0] = 1; hex16[1] = 1;
		}
		else if (hex16[0] == 1 && hex16[1] == 0)
		{
			hex16[0] = 0; hex16[1] = 0;
		}
		else
		{
			hex16[0] = 0; hex16[1] = 1;
		}

		int d = 0;
		for (int bow = 0; bow < save - 1; bow++)   //2의 보수를 10진수로 변환
		{
			d = d + hex16[bow] * (pow(2, bow));
		}   //d는 변환된 10진수

		int q = 0; int ba; int ca;      //10진수 d를 16진수로 변환
		do
		{
			ba = d / 16;
			ca = d % 16;
			hfinal[q] = h[ca];     //최종적으로 변환된 16진수는 hfinal[]에 저장됨
			q++;
			d = ba;
		} while (ba >= 16);

		hfinal[q] = h[ba];
		int dd = q;

		//최종적으로 변환한 16진수 출력
		printf("16진수 : 0x");
		do
		{
			printf("%c", hfinal[dd]);
			dd--;
		} while (dd >= 0);

	}

	//입력받은 양수 10진수 --> 16진수
	else     
	{
		int a = 0; int b; int c;
		do
		{
			b = userget16 / 16;
			c = userget16 % 16;
			h16[a] = h[c];
			a++;
			userget16 = b;
		} while (b >= 16);

		h16[a] = h[b];
		int d = a;

		//변환한 16진수값 출력
		printf("16진수 : ");
		do
		{
			printf("%c", h16[d]);
			d--;
		} while (d >= 0);

	}

	printf("\n");

	//입력받은 음수 10진수 --> 8진수
	if (fix8 < 0)   
	{
		fix8 = fix8 * -1;  //입력받은 10진수 음수의 절댓값 구하기
		int u = 0;

		while (u <= 12)    //절댓값을 이진수로 변환
		{
			if (fix8 > 0)
			{
				octal[u] = fix8 % 2;
				fix8 = fix8 / 2;
				u++;
			}
			else
			{
				octal[u] = 0;
				u++;
			}

		}
		int won = u;

		for (int s = 0; s < won; s++)      //octal[] 에 대한 1의 보수 구하기
		{
			if (octal[s] == 1)
			{
				octal[s] = 0;
			}
			else
			{
				octal[s] = 1;
			}
		}

		int sav = won;

		if (octal[0] == 0 && octal[1] == 0)        //octal[]에 대한 2의 보수 구하기(이진수 덧셈 => 십진수 1, 즉 이진수 01 을 더하기)
		{
			octal[0] = 1; octal[1] = 0;
		}
		else if (octal[0] == 0 && octal[1] == 1)
		{
			octal[0] = 1; octal[1] = 1;
		}
		else if (octal[0] == 1 && octal[1] == 0)
		{
			octal[0] = 0; octal[1] = 0;
		}
		else
		{
			octal[0] = 0; octal[1] = 1;
		}

		int ru = 0;
		for (int bow = 0; bow < sav - 1; bow++)   //2의 보수를 10진수로 변환
		{
			ru = ru + octal[bow] * (pow(2, bow));
		}   //ru는 변환된 10진수

		int ii = 0; int n; int m;		//변환된 10진수를 최종적으로 8진수로 변환
		do
		{
			m = ru / 8;
			n = ru % 8;
			octal[ii] = n;
			ii++;
			ru = m;
		} while (m >= 8);

		octal[ii] = m;
		int aa = ii;

		//최종적으로 변환한 8진수 출력
		printf("8진수 : ");
		do
		{
			printf("%d", octal[aa]);
			aa--;
		} while (aa >= 0);
	}

	//입력받은 양수 10진수 --> 8진수
	else       
	{
		int ii = 0; int n; int m;
		do
		{
			m = fix8 / 8;
			n = fix8 % 8;
			h8[ii] = n;
			ii++;
			fix8 = m;
		} while (m >= 8);

		h8[ii] = m;
		int aa = ii;

		//최종적으로 변환한 8진수 출력
		printf("8진수 : ");
		do
		{
			printf("%d", h8[aa]);
			aa--;
		} while (aa >= 0);
	}

	return 0;
}