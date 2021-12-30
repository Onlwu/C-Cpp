#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintRSP(char *name, int hand)//���������� ���
{
	char cRSP[3][5] = { "����","����","��" };
	printf("%s : %s\n",name, cRSP[hand - 1]);
	return;
}
void PrintWL(int i)//���� �޽��� ���
{
	switch (i)
	{
	case 1:
		printf("��� : ������������ �̰���ϴ�.");
		break;
	case 2:
		printf("��� : ������������ �����ϴ�.");
		break;
	case 3:
		printf("��� : ������������ �����ϴ�.");
		break;
	}
	printf("\n");
	return;
}
int main()
{
	srand(time(NULL));
	int Myhand; // �� �� ����
	int Comhand = rand() % 3 + 1;; // ��ǻ�� �� ����
	while (1)
	{
		printf("���������� ����\n1.���� 2. ���� 3.�� 0. ����\n�Է����ּ��� : ");
		scanf_s("%d", &Myhand);
		if (Myhand > 0 && Myhand <= 3) break;
		else if (Myhand == 0) exit(0);
		else printf("�ٽ� �Է� ���ּ���.\n");
	}

	PrintRSP("��ǻ��", Comhand);
	PrintRSP("�����", Myhand);
	switch (Myhand - Comhand)//Ȯ�������� �� ���� �� ������ ��
	{
		case -1:
			PrintWL(2);
			break;
		case 1 :
			PrintWL(1);
			break;
		case 2 :
			PrintWL(2);
			break;
		case -2:
			PrintWL(1);
			break;
		case 0:
			PrintWL(3);
			break;
	}
}