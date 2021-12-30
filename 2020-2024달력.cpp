#include<stdio.h>
#include<windows.h> 
#define StartDay 3 // 1 = 월요일 2= 화요일....


int main()
{
	int i = 0;
	printf("★2020~2024까지의 달력을 보실 수 있습니다!!★\n");
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, iM, iY;//im iy는 구별할려고
	
	printf("보고싶은 날짜의 '년'을 입력해주세요 : \n");
	scanf_s("%d", &iY);
	printf("보고싶은 날짜의 '월'을 입력해주세요 : \n0을 입력 시 년 전체가 출력됩니다!\n");
	scanf_s("%d", &iM);
	
	int End_Month = iM;
	
	//2020.1.1 수요일을 1이나 3으로 만들어서 관리 그 이후 %7로 하면 월화수목금토일 20년 24년 윤년
	if (iM ==0)//0누르면 년 모두 출력
	{
		iM = 1;//1월부터 출력을 위해
		End_Month = 12;//12월까지 출력
	}
	
	int setYear = iY - 2020;//2020년 0으로 만들기 2021=1,  몇년차인지 나타냄

	for (;iM<=End_Month; iM++)// 1월~12월
	{
		int sumDays = setYear * 365;//년계산
		
		if (setYear % 4 == 0)//윤년 1일 추가 계산
		{
			month[1] = 29;
		}
		if (setYear > 0)//윤년 1일 추가 계산 2020 일때랑 2024때 진입
		{
			sumDays++;
		}
			for (int i = 0; i < iM - 1; i++)//월계산
			{
				sumDays += month[i];
				//printf("sumday3는 %d", sumDays);//sum3
			}
			printf("\n\n%d년 %d월 달력\n\n", iY, iM);
			printf("월\t화\t수\t목\t금\t토\t일\n");
			printf("\n=============================================================================\n");

			sumDays += StartDay;//요일 수요일부터 시작 sumday는 요일을 위해 존재
		
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
