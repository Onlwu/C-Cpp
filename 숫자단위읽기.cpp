#include<stdio.h>
#include <stdlib.h> 
#include<string.h>
#define NN 4//만단위
#define GG 4//만단위 이후 

int main()
{
	
	//0 ~ 18,446,744,073,709,551,615 셀 수 있다. 자료형 	unsigned long long  이므로
	printf("자연수의 숫자단위를 자동적으로 적어줍니다.\n예) 1000000 -> 100만 0000\n\n");
	printf("0 ~ 18,446,744,073,709,551,615 셀 수 있다.\n");
	int pn[100];
	unsigned long long num;
	int j=0;
	printf("숫자를 입력하세요\n");
	//%llu
	scanf_s("%llu", &num);
	printf("num의 입력값은 : %lld\n", num);
	do {
		for (int i = 0; i < 10; i++) //일의 자리부터 계산됨 마지막 단위 0~9
		{
			if ((num - i) % 10 == 0)// 일의 단위 맞추면			
			{
				num = (num - i) / 10; // 한자리씩 내리기
				pn[j] = i;
				j++;
				break;
			}
		}
	} while (num > 0);
	
	j--; // 배열은 숫자 -1이 맞는 번호다.


	for (; j >=0 ; j--)//내리순으로 
	{
		printf("%d", pn[j]);
		switch(j)
		{
		case NN:
			printf("만 ");
			break;
		case NN + GG:
			printf("억 ");
			break;
		case NN + GG*2:
			printf("경 ");
			break;
		case NN + GG*3:
			printf("조 ");
			break;
//여기서부터는 의미가 없음 ㅠㅠ longlong 자료형의 한계
		case NN + GG*4:
			printf("해 ");
			break;
		case NN + GG*5:
			printf("자 ");
			break;
		case NN + GG*6:
			printf("양 ");
			break;
		case NN + GG*7:
			printf("구 ");
			break;
		case NN + GG*8:
			printf("간 ");
			break;
		case NN + GG*9:
			printf("정 ");
			break;
		case NN + GG*10:
			printf("재 ");
			break;
		case NN + GG*11:
			printf("극 ");
			break;
		default:
			break;	
		}
	}
	printf("\n종료하려면 아무 키나 누르세요.\n");
	system("PAUSE");
	getchar();

}