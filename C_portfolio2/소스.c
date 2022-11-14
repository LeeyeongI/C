#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


int map[10][10][10] = { 0 };
int i, j, k;
int second = 0, interval = 0; // second = 눈이 내리는 시간, interval = 눈이 내리는 간격
int x[5] = { 0 }, y[5] = { 0 }; // 눈이 내리는 위치 x,y값을 받는 변수
int count = 0; // 좌우키의 입력을 받아 값을 저장하는 변수
int z = 0;// z값을 저장하는 변수
char key; // 좌우키, 스페이스바를 입력받는 변수


void start();
void screen();
void map_print_top();
void map_print_front();
int random();
void new_snow();
void snow_pst();
void map_print_right();
void map_print_back();
void map_print_left();
void map_turn();
void snow();
void snowing();



void main()
{
	srand(time(NULL));
	start();
	snowing();
}


void start()// 시작할때 눈이 내리는 시간과 간격을 설정하는 함수
{
	system("cls");
	printf("눈이 내리는 시간을 설정해주세요.(정수로 입력해주세요) ");
	scanf("%d", &second);
	printf("눈이 내리는 간격을 설정해주세요.(Sleep) ");
	scanf("%d", &interval);
	system("cls");
}
void screen()// 초기화면으로 돌아가 눈이 내리는 시간과 간격을 설정하거나 프로그램을 종료하는 함수
{
	int q = 0;
	system("cls");
	printf("1.눈을 더 보고 싶어요.\n2.이제 그만 볼래요.\n");
	scanf("%d", &q);
	while (q != 1 && q != 2)
	{
		system("cls");
		printf("다시 입력해주세요.\n");
		printf("1.눈을 더 보고 싶어요.\n2.이제 그만 볼래요.\n");
		scanf("%d", &q);
	}
	if (q == 1)
	{
		system("cls");
		printf("눈이 내리는 시간을 설정해주세요.(정수로 입력해주세요) ");
		scanf("%d", &second);
		printf("눈이 내리는 간격을 설정해주세요.(Sleep) ");
		scanf("%d", &interval);
		system("cls");
		snowing();
	}
	else if (q == 2)
	{
		system("cls");
		printf("\t∴▲∴△∴▲∴△∴\n\t∴▲∴△∴▲∴△∴\n\t∴∥∴∥∴∥∴∥∴\n");
		printf("\t MERRY CHRISTMAS!!\n");
	}
}
void map_print_top()//맵의 윗면을 출력해주는 함수
{
	for (i = 0; i < 5; i++)
	{
		map[z][y[i]][x[i]] = 0;
		map[9][y[i]][x[i]] = 1;
	}
	for (j = 0; j < 10; j++)
	{
		for (k = 0; k < 10; k++)
		{
			if (map[9][j][k] == 1) printf("●");
			else if (map[9][j][k] == 0) printf("□");
		}
		printf("\n");
	}
	printf("[윗면]\n");
	printf("\n");
	new_snow();
}
void map_print_front()//맵의 정면을 출력해주는 함수
{

	for (i = 0; i < 5; i++)
	{
		map[z][9][x[i]] = 1;
	}
	for (i = 9; i >= 0; i--)
	{
		for (k = 0; k < 10; k++)
		{
			if (map[i][9][k] == 1) printf("∴");
			else if (map[i][9][k] == 0)	printf("□");
		}
		printf("\n");
	}
	printf("[정면]\n");
	new_snow();
}
int random()// 눈의 위치를 랜덤으로 생성하기 위해 좌표값을 받는 함수
{
	int r = 0;
	r = rand() % 10;
	return r;
}
void new_snow() // map 배열을 초기화 해주는 함수
{
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			for (k = 0; k < 10; k++)
			{
				map[i][j][k] = 0;
			}
		}
	}
}
void snow_pst()//눈의 좌표값을 받는 함수
{
	new_snow();
	for (i = 0; i < 5; i++)
	{
		x[i] = random();
		y[i] = random();
	}
	z = 9;
}
void map_print_right() //맵의 오른쪽면을 출력하는 함수
{
	for (i = 0; i < 5; i++)
	{
		map[z][y[i]][9] = 1;
	}
	for (i = 9; i >= 0; i--)
	{
		for (j = 9; j >= 0; j--)
		{
			if (map[i][j][9] == 1) printf("★");
			else if (map[i][j][9] == 0)	printf("□");
		}
		printf("\n");
	}
	printf("[오른쪽]\n");
	new_snow();
}
void map_print_back()//맵의 뒷면을 출력하는 함수
{
	for (i = 0; i < 5; i++)
	{
		map[z][0][x[i]] = 1;
	}
	for (i = 9; i >= 0; i--)
	{
		for (k = 9; k >= 0; k--)
		{
			if (map[i][0][k] == 1) printf("◆");
			else if (map[i][0][k] == 0)	printf("□");
		}
		printf("\n");
	}
	printf("[뒷면]\n");
	new_snow();
}
void map_print_left()//맵의 왼쪽면을 출력하는 함수
{
	for (i = 0; i < 5; i++)
	{
		map[z][y[i]][0] = 1;
	}
	for (i = 9; i >= 0; i--)
	{
		for (j = 0; j < 10; j++)
		{
			if (map[i][j][0] == 1) printf("♥");
			else if (map[i][j][0] == 0)	printf("□");
		}
		printf("\n");
	}
	printf("[왼쪽]\n");
	new_snow();
}
void map_turn() // 눈이 다 내린뒤에 좌우키를 이용해 화면을 이동하는 함수
{
	printf("\n스페이스바를 누르시면 초기화면으로 돌아갈 수 있습니다.(초기화면에서 끝내기 가능)\n");
	printf("좌우키를 이용해 화면을 이동할 수 있습니다.\n");
	key = _getch(); // 스페이스바 32 좌 75 우 77
	while (key != 32)
	{
		if (key == 77) count++;
		if (key == 75) count--;
		if (count == 4) count = 0;
		if (count == -1) count = 3;

		if (count == 0) //count가 0일때 정면 출력
		{
			system("cls");
			map_print_top();
			map_print_front();
		}
		else if (count == 1) //count가 1일때 오른쪽면 출력
		{
			system("cls");
			map_print_top();
			map_print_right();
		}
		else if (count == 2) //count가 2일때 뒷면 출력
		{
			system("cls");
			map_print_top();
			map_print_back();
		}
		else if (count == 3) //count가 3일때 왼쪽면 출력
		{
			system("cls");
			map_print_top();
			map_print_left();
		}
		printf("\n스페이스바를 누르시면 초기화면으로 돌아갈 수 있습니다.(초기화면에서 끝내기 가능)\n");
		printf("좌우키를 이용해 화면을 이동할 수 있습니다.\n");
		key = _getch();
	}
	count = 0;
	screen();
}
void snow() // 눈이 내릴때 이용할 함수
{
	new_snow();
	for (i = 0; i < 5; i++)
	{
		map[z][y[i]][x[i]] = 1;
	}
	for (j = 0; j < 10; j++)
	{
		for (k = 0; k < 10; k++)
		{
			if (map[z][j][k] == 1)
			{
				map[z][j][k] = 0;
				z--;
				if (z == -1) 	z = 9;
			}
		}
	}
	Sleep(interval);
	system("cls");
	map_print_top();  map_print_front();
}
void snowing() //눈이 내리는 함수
{
	int count = 0, m = 0;
	snow_pst();
	map_print_top();
	map_print_front();
	m = (second * 1000) / interval;
	while (count < m)
	{
		snow();
		count++;
	}
	map_turn();
}