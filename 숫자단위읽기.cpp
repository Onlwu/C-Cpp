#include<stdio.h>
#include <stdlib.h> 
#include<string.h>
#define NN 4//������
#define GG 4//������ ���� 

int main()
{
	
	//0 ~ 18,446,744,073,709,551,615 �� �� �ִ�. �ڷ��� 	unsigned long long  �̹Ƿ�
	printf("�ڿ����� ���ڴ����� �ڵ������� �����ݴϴ�.\n��) 1000000 -> 100�� 0000\n\n");
	printf("0 ~ 18,446,744,073,709,551,615 �� �� �ִ�.\n");
	int pn[100];
	unsigned long long num;
	int j=0;
	printf("���ڸ� �Է��ϼ���\n");
	//%llu
	scanf_s("%llu", &num);
	printf("num�� �Է°��� : %lld\n", num);
	do {
		for (int i = 0; i < 10; i++) //���� �ڸ����� ���� ������ ���� 0~9
		{
			if ((num - i) % 10 == 0)// ���� ���� ���߸�			
			{
				num = (num - i) / 10; // ���ڸ��� ������
				pn[j] = i;
				j++;
				break;
			}
		}
	} while (num > 0);
	
	j--; // �迭�� ���� -1�� �´� ��ȣ��.


	for (; j >=0 ; j--)//���������� 
	{
		printf("%d", pn[j]);
		switch(j)
		{
		case NN:
			printf("�� ");
			break;
		case NN + GG:
			printf("�� ");
			break;
		case NN + GG*2:
			printf("�� ");
			break;
		case NN + GG*3:
			printf("�� ");
			break;
//���⼭���ʹ� �ǹ̰� ���� �Ф� longlong �ڷ����� �Ѱ�
		case NN + GG*4:
			printf("�� ");
			break;
		case NN + GG*5:
			printf("�� ");
			break;
		case NN + GG*6:
			printf("�� ");
			break;
		case NN + GG*7:
			printf("�� ");
			break;
		case NN + GG*8:
			printf("�� ");
			break;
		case NN + GG*9:
			printf("�� ");
			break;
		case NN + GG*10:
			printf("�� ");
			break;
		case NN + GG*11:
			printf("�� ");
			break;
		default:
			break;	
		}
	}
	printf("\n�����Ϸ��� �ƹ� Ű�� ��������.\n");
	system("PAUSE");
	getchar();

}