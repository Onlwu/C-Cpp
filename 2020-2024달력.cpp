#include<stdio.h>
#include<windows.h> 
#define StartDay 3 // 1 = 월요일 2= 화요일....


int main()
{
	int i = 0;
	/*
			2020년부터 2024년까지의 달
	년도와 월을 입력하는 해당 월
		연도만 입력하면 1~12월 모두
		사용자가 원하는 만큼 사용할
		프로그램을 다시 시작하지 않고 계속 사용할 수 있어야 합니다.
		해당 월과 년도는 콘솔에서 입력할 수 있어야 합니다.
		최대한 라인수를 줄여서 작성하세요

		20.1.1 => 수
	*/
	// 31 : 1 3 5 7 8 10 12   / 30 : 4 6 9 11   / 2 28
	printf("★2020~2024까지의 달력을 보실 수 있습니다!!★\n");
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, iM, iY;//im iy는 구별할려고
	printf("보고싶은 날짜의 '년'을 입력해주세요 : \n");
	scanf_s("%d", &iY);
	printf("보고싶은 날짜의 '월'을 입력해주세요 : \n0을 입력 시 년 전체가 출력됩니다!\n");
	scanf_s("%d", &iM);
	int End_Month = iM;
	//2020.1.1 수요일을 1이나 3으로 만들어서 관리 그 이후 %7로 하면 월화수목금토일 20년 24년 윤녕
	if (iM ==0)//0누르면 년 모두 출력
	{
		iM = 1;//1월부터 출력을 위해
		End_Month = 12;//12월까지 출력
	}



	int setYear = iY - 2020;//2020년 0으로 만들기 2021=1,  몇년차인지 나타냄

	//printf("setyear는 %d", setYear);

	for (;iM<=End_Month; iM++)// 1월~12월
	{

		int sumDays = setYear * 365;//년계산

		//printf("sumday1는 %d", sumDays);//sum1

		if (setYear % 4 == 0)//윤년 1일 추가 계산
		{
			month[1] = 29;
		}
		if (setYear > 0)//윤년 1일 추가 계산 2020 일때랑 2024때 진입
		{
			//sumDays += (setYear / 4) + 1;
			sumDays++;
			//printf("sumday2는 %d", sumDays);//sum2
		}
		//printf("iM은 %d", iM);
		//for (iM = 1; iM < 13; iM++)
		//{
			for (int i = 0; i < iM - 1; i++)//월계산
			{
				sumDays += month[i];
				//printf("sumday3는 %d", sumDays);//sum3
			}
			//printf("\n\n총일수 : %d일\n\n", sumDays);
			printf("\n\n%d년 %d월 달력\n\n", iY, iM);


			//iM = StartDay + sumDays;
			//printf("섬추가 IM : %d\n\n", iM);

			printf("월\t화\t수\t목\t금\t토\t일\n");
			printf("\n=============================================================================\n");

			sumDays += StartDay;//요일 수요일부터 시작 sumday는 요일을 위해 존재
			//printf("sum %d &7 %d\n", sumDays, sumDays % 7);
			//sumDays += 7;//지우기
			for (i = 1; i <sumDays % 7; i++)//총요일 4 i는 일짜 세줌
			{
				printf("\t");
			}
			if (sumDays % 7 == 0)//일요일은 %7할 시 0이 떠서 아무것도 안찍음 때문에 이 식 필요.
			{
				for (i = 1; i < 7; i++)//총요일 4 i는 일짜 세줌
				{
					printf("\t");
				}
			}
			printf(" ");//양식맞추기
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