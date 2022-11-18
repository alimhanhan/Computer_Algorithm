#include <stdio.h>
#include <math.h>
#include <limits.h>

int binary[31];			//2������ ��ȯ�� ���� ����� �迭
int userget = 0;		//����ڷκ��� �Է¹޴� ����
char h[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };   //16�������� ��Ÿ�� �� �ִ� ���ڸ� ���������� �����ϰ� �ִ� �迭
char h16[32];  //16������ ��ȯ�� ���� ����� �迭
char hfinal[32];    //���������� ��ȯ�� 16���� ���� ����� �迭 -> ����ڷκ��� �Է¹��� ���� ������ ��쿡�� ���
int hex16[32];    //1�� ������ 2�� ������ ���ϴ� �������� ���� �迭
int h8[32];    //�޾Ƶ��� 10���� ��� --> 8������ ��ȯ�� ���� ����� �迭
int octal[32];  //�޾Ƶ��� 10���� ���� --> 8���� ���������� ���
				//8������ ��ȯ�� ���� ����� �迭


int main() 
{	
	//����ڷκ��� ���� �Է¹ޱ�
	printf("������ �Է��Ͻÿ� : ");   
	scanf_s("%d", &userget);

	//���� �Է°� ������ ���� ���� ���� ����
	int fix2 = userget;       //10 -> 2���� �� ���
	int userget16 = userget;  //10 -> 16���� �� ���
	int fix8 = userget;       //10 -> 8���� �� ���

	//�Է¹��� ��� 10���� --> 2����
	if (fix2 >= 0)   
	{
		int i = 0;     //������ ����� ���� ���� i

		while (fix2 > 0)
		{
			binary[i] = fix2 % 2;  //�迭 binary�� fix2�� 2�� ���� ������ ����
			fix2 = fix2 / 2;    //fix2�� 2�� ���� ���� ���ο� fix2�� ��
			i++;    
		}

		//��ȯ�� 2������ ���
		printf("2���� : ");
		for (int kor=i; kor >= 0; kor--)
		{
			printf("%d", binary[kor]);
		}

	}

	//�Է¹��� ���� 10���� --> 2����
	else      
	{
		int i = 0;       //������ ����� ���� ���� i

		fix2 = fix2 + 1;
		fix2 = fix2 * -1;   //�Է¹��� ������ ���� ���ϱ�

		while (fix2 > 0)    //������ �������� ��ȯ
		{
			binary[i] = fix2 % 2;
			fix2 = fix2 / 2;
			i++;
		}
		int kor = i;

		printf("2���� : ");
		for (kor = i; kor >= 0; kor--)
		{
			printf("%d", !(binary[kor]));    //! �����ڸ� ����Ͽ� ��Ʈ �������� ���
		}

	}

	printf("\n");		//�� �ٲ�

	//�Է¹��� ���� 10���� --> 16����
	if (userget16 < 0)      
	{
		userget16 = userget16 * -1;  //�Է¹��� 10���� ������ ���� ���ϱ�
		int i = 0;
		
		while (i<=12)    //������ �������� ��ȯ
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
		
		for (int s =0; s <ex; s++)      //hex16[] �� ���� 1�� ���� ���ϱ�
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
		
		if (hex16[0] == 0 && hex16[1] == 0)        //hex16[]�� ���� 2�� ���� ���ϱ�(������ ���� => ������ 1, �� ������ 01 �� ���ϱ�)
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
		for (int bow = 0; bow < save - 1; bow++)   //2�� ������ 10������ ��ȯ
		{
			d = d + hex16[bow] * (pow(2, bow));
		}   //d�� ��ȯ�� 10����

		int q = 0; int ba; int ca;      //10���� d�� 16������ ��ȯ
		do
		{
			ba = d / 16;
			ca = d % 16;
			hfinal[q] = h[ca];     //���������� ��ȯ�� 16������ hfinal[]�� �����
			q++;
			d = ba;
		} while (ba >= 16);

		hfinal[q] = h[ba];
		int dd = q;

		//���������� ��ȯ�� 16���� ���
		printf("16���� : 0x");
		do
		{
			printf("%c", hfinal[dd]);
			dd--;
		} while (dd >= 0);

	}

	//�Է¹��� ��� 10���� --> 16����
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

		//��ȯ�� 16������ ���
		printf("16���� : ");
		do
		{
			printf("%c", h16[d]);
			d--;
		} while (d >= 0);

	}

	printf("\n");

	//�Է¹��� ���� 10���� --> 8����
	if (fix8 < 0)   
	{
		fix8 = fix8 * -1;  //�Է¹��� 10���� ������ ���� ���ϱ�
		int u = 0;

		while (u <= 12)    //������ �������� ��ȯ
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

		for (int s = 0; s < won; s++)      //octal[] �� ���� 1�� ���� ���ϱ�
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

		if (octal[0] == 0 && octal[1] == 0)        //octal[]�� ���� 2�� ���� ���ϱ�(������ ���� => ������ 1, �� ������ 01 �� ���ϱ�)
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
		for (int bow = 0; bow < sav - 1; bow++)   //2�� ������ 10������ ��ȯ
		{
			ru = ru + octal[bow] * (pow(2, bow));
		}   //ru�� ��ȯ�� 10����

		int ii = 0; int n; int m;		//��ȯ�� 10������ ���������� 8������ ��ȯ
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

		//���������� ��ȯ�� 8���� ���
		printf("8���� : ");
		do
		{
			printf("%d", octal[aa]);
			aa--;
		} while (aa >= 0);
	}

	//�Է¹��� ��� 10���� --> 8����
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

		//���������� ��ȯ�� 8���� ���
		printf("8���� : ");
		do
		{
			printf("%d", h8[aa]);
			aa--;
		} while (aa >= 0);
	}

	return 0;
}