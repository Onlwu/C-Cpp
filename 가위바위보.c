#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintRSP(char *name, int hand)//가위바위보 출력
{
	char cRSP[3][5] = { "가위","바위","보" };
	printf("%s : %s\n",name, cRSP[hand - 1]);
	return;
}
void PrintWL(int i)//승패 메시지 출력
{
	switch (i)
	{
	case 1:
		printf("결과 : 가위바위보를 이겼습니다.");
		break;
	case 2:
		printf("결과 : 가위바위보를 졌습니다.");
		break;
	case 3:
		printf("결과 : 가위바위보를 비겼습니다.");
		break;
	}
	printf("\n");
	return;
}
int main()
{
	srand(time(NULL));
	int Myhand; // 내 손 상태
	int Comhand = rand() % 3 + 1;; // 컴퓨터 손 상태
	while (1)
	{
		printf("가위바위보 게임\n1.가위 2. 바위 3.보 0. 종료\n입력해주세요 : ");
		scanf_s("%d", &Myhand);
		if (Myhand > 0 && Myhand <= 3) break;
		else if (Myhand == 0) exit(0);
		else printf("다시 입력 해주세요.\n");
	}

	PrintRSP("컴퓨터", Comhand);
	PrintRSP("사용자", Myhand);
	switch (Myhand - Comhand)//확률적으로 잘 나올 것 같은거 순
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