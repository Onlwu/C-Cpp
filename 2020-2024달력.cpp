#include<stdio.h>
#include<windows.h> 
#define StartDay 3 // 1 = ������ 2= ȭ����....


int main()
{
	int i = 0;
	/*
			2020����� 2024������� ��
	�⵵�� ���� �Է��ϴ� �ش� ��
		������ �Է��ϸ� 1~12�� ���
		����ڰ� ���ϴ� ��ŭ �����
		���α׷��� �ٽ� �������� �ʰ� ��� ����� �� �־�� �մϴ�.
		�ش� ���� �⵵�� �ֿܼ��� �Է��� �� �־�� �մϴ�.
		�ִ��� ���μ��� �ٿ��� �ۼ��ϼ���

		20.1.1 => ��
	*/
	// 31 : 1 3 5 7 8 10 12   / 30 : 4 6 9 11   / 2 28
	printf("��2020~2024������ �޷��� ���� �� �ֽ��ϴ�!!��\n");
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, iM, iY;//im iy�� �����ҷ���
	printf("������� ��¥�� '��'�� �Է����ּ��� : \n");
	scanf_s("%d", &iY);
	printf("������� ��¥�� '��'�� �Է����ּ��� : \n0�� �Է� �� �� ��ü�� ��µ˴ϴ�!\n");
	scanf_s("%d", &iM);
	int End_Month = iM;
	//2020.1.1 �������� 1�̳� 3���� ���� ���� �� ���� %7�� �ϸ� ��ȭ��������� 20�� 24�� ����
	if (iM ==0)//0������ �� ��� ���
	{
		iM = 1;//1������ ����� ����
		End_Month = 12;//12������ ���
	}



	int setYear = iY - 2020;//2020�� 0���� ����� 2021=1,  ��������� ��Ÿ��

	//printf("setyear�� %d", setYear);

	for (;iM<=End_Month; iM++)// 1��~12��
	{

		int sumDays = setYear * 365;//����

		//printf("sumday1�� %d", sumDays);//sum1

		if (setYear % 4 == 0)//���� 1�� �߰� ���
		{
			month[1] = 29;
		}
		if (setYear > 0)//���� 1�� �߰� ��� 2020 �϶��� 2024�� ����
		{
			//sumDays += (setYear / 4) + 1;
			sumDays++;
			//printf("sumday2�� %d", sumDays);//sum2
		}
		//printf("iM�� %d", iM);
		//for (iM = 1; iM < 13; iM++)
		//{
			for (int i = 0; i < iM - 1; i++)//�����
			{
				sumDays += month[i];
				//printf("sumday3�� %d", sumDays);//sum3
			}
			//printf("\n\n���ϼ� : %d��\n\n", sumDays);
			printf("\n\n%d�� %d�� �޷�\n\n", iY, iM);


			//iM = StartDay + sumDays;
			//printf("���߰� IM : %d\n\n", iM);

			printf("��\tȭ\t��\t��\t��\t��\t��\n");
			printf("\n=============================================================================\n");

			sumDays += StartDay;//���� �����Ϻ��� ���� sumday�� ������ ���� ����
			//printf("sum %d &7 %d\n", sumDays, sumDays % 7);
			//sumDays += 7;//�����
			for (i = 1; i <sumDays % 7; i++)//�ѿ��� 4 i�� ��¥ ����
			{
				printf("\t");
			}
			if (sumDays % 7 == 0)//�Ͽ����� %7�� �� 0�� ���� �ƹ��͵� ������ ������ �� �� �ʿ�.
			{
				for (i = 1; i < 7; i++)//�ѿ��� 4 i�� ��¥ ����
				{
					printf("\t");
				}
			}
			printf(" ");//��ĸ��߱�
			i = i - iM + 1;
			for (int j = 1; j <= month[iM - 1]; j++)// iM
			{
				printf("%2d\t ", j);
				if ((i + iM) % 7 == 1)
				{
					printf("\n");
				}
				i++;
			}
			printf("\n=============================================================================\n");
	}
		system("pause");
	
	
	
	return 0;
}