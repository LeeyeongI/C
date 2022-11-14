#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int map[12][12] =
{ { 0,0,0,0,0,0,0,0,0,0,0,0 },
  { 0,0,1,0,0,1,0,0,0,0,0,0 },
  { 0,0,1,0,0,1,0,0,1,1,1,0 },
  { 0,0,1,0,0,1,0,0,0,0,0,0 },
  { 0,0,1,0,0,1,0,0,0,0,0,0 },
  { 0,0,0,0,0,0,0,0,1,1,1,0 },
  { 0,0,0,0,0,0,0,0,0,0,0,0 },
  { 0,1,1,1,1,0,1,0,0,1,0,0 },
  { 0,0,0,0,0,0,1,0,0,1,0,0 },
  { 0,0,0,0,0,0,1,0,0,1,0,0 },
  { 0,1,1,1,1,0,1,0,0,1,0,0 },
  { 0,0,0,0,0,0,0,0,0,0,0,0 } };
int me_x = 0, me_y = 0, i, j;
int x = 0, y = 0, s = 0, t = 0, a = 0, b = 0;

void person();
void home_arrive();
void pointer();
void map_print();
void start();
int random_value();
void limit_1();
void limit_2();
void limit_3();
void limit_4();
void limit_home();
void person_move();
void pointer_move();
void key_move();
void move();

void main()
{
	srand(time(NULL));
	start();
	move();
	map_print();
	printf("I'm home!!\n");
}


void person()
{
	int count = 1;
	while (count != 0) {
		x = rand() % 12;
		y = rand() % 12;
		if (map[y][x] != 0) {
			count = 1;
		}
		else {
			count = 0;
		}
	}
	me_x = x; me_y = y;
}
void home_arrive()
{
	int count = 1;
	while (count != 0) {
		if (y >= 0 && y < 6 && x >= 0 && x < 6) {
			b = rand() % 6 + 6; a = rand() % 6 + 6;
		}
		else if (y >= 0 && y < 6 && x > 5 && x < 12) {
			b = rand() % 6 + 6; a = rand() % 6;
		}
		else if (y > 5 && y < 12 && x >= 0 && x < 6) {
			b = rand() % 6; a = rand() % 6 + 6;
		}
		else if (y > 5 && y < 12 && x > 5 && x < 12) {
			b = rand() % 6; a = rand() % 6;
		}
		if (map[b][a] != 0) {
			count = 1;
		}
		else {
			count = 0;
		}
	}
}
void pointer()
{
	int count = 1;
	while (count != 0) {
		if (y >= 0 && y < 6 && x >= 0 && x < 6) {
			t = rand() % 6; s = rand() % 6;
		} //1사분면
		else if (y >= 0 && y < 6 && x > 5 && x < 12) {
			t = rand() % 6; s = rand() % 6 + 6;
		}//2사분면
		else if (y > 5 && y < 12 && x >= 0 && x < 6) {
			t = rand() % 6 + 6; s = rand() % 6;
		}//3사분면
		else if (y > 5 && y < 12 && x > 5 && x < 12) {
			t = rand() % 6 + 6; s = rand() % 6 + 6;
		}//4사분면
		if (map[t][s] != 0) {
			count = 1;
		}
		else {
			count = 0;
		}
	}
}
void map_print()
{
	system("cls");
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (x == j && y == i) {
				printf("♬"); // 술 취한 사람 
			}
			else if (s == j && t == i) {
				printf("＠"); // 행인
			}
			else if (me_y == i && me_x == j) {
				printf("P "); // 펍
			}
			else if (a == j && b == i) {
				printf("▣"); // 집
			}
			else if (map[i][j] == 0) {
				printf("  "); // 길
			}
			else if (map[i][j] == 2) {
				printf("  "); //막힌 길
			}
			else if (map[i][j] == 1) {
				printf("■"); // 벽
			}
		}
		printf("\n");
	}
}
void start()
{
	person();
	home_arrive();
	pointer();
	map_print();
}
int random_value()
{
	int value;
	value = rand() % 4; // 0 위 1 왼 2 오 3 아래
	return value;
}
void limit_1()
{
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 2;
			}
		}
	}
}
void limit_2() {
	for (i = 0; i < 6; i++) {
		for (j = 6; j < 12; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 2;
			}
		}
	}
}
void limit_3()
{
	for (i = 6; i < 12; i++) {
		for (j = 0; j < 6; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 2;
			}
		}
	}
}
void limit_4()
{
	for (i = 6; i < 12; i++) {
		for (j = 6; j < 12; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 2;
			}
		}
	}
}
void limit_home()
{
	if (b >= 0 && b < 6 && a >= 0 && a < 6) {
		if (y >= 0 && y < 6 && x >= 0 && x < 6) {
			limit_2(); limit_3(); limit_4();
		}
	}
	else if (b >= 0 && b < 6 && a > 5 && a < 12) {
		if (y >= 0 && y < 6 && x > 5 && x < 12) {
			limit_1(); limit_3(); limit_4();
		}
	}
	else if (b > 5 && b < 12 && a >= 0 && a < 6) {
		if (y > 5 && y < 12 && x >= 0 && x < 6) {
			limit_1(); limit_2(); limit_4();
		}
	}
	else if (b > 5 && b < 12 && a > 5 && a < 12) {
		if (y > 5 && y < 12 && x > 5 && x < 12) {
			limit_1(); limit_2(); limit_3();
		}
	}
}
void person_move()
{
	int m = 0;
	m = random_value();
	if (m == 0 && map[y - 1][x] == 0 && y > 0) {
		y--;
		if (y == 5) {
			pointer();
			if (x >= 0 && x < 6) {
				limit_3();
			}
			else {
				limit_4();
			}
		}
	}
	if (m == 1 && map[y][x - 1] == 0 && x > 0) {
		x--;
		if (x == 5) {
			pointer();
			if (y >= 0 && y < 6) {
				limit_2();
			}
			else {
				limit_4();
			}
		}
	}
	if (m == 2 && map[y][x + 1] == 0 && x < 11) {
		x++;
		if (x == 6) {
			pointer();
			if (y >= 0 && y < 6) {
				limit_1();
			}
			else {
				limit_3();
			}
		}

	}
	if (m == 3 && map[y + 1][x] == 0 && y < 11) {
		y++;
		if (y == 6) {
			pointer();
			if (x >= 0 && x < 6) {
				limit_1();
			}
			else {
				limit_2();
			}
		}
	}
}
void pointer_move()
{
	int m = 0;
	m = random_value();
	if (m == 0 && t > 0 && map[t - 1][s] == 0 && t != 6) {
		if (t - 1 != b || s != a) {
			t--;
		}
	}
	if (m == 1 && s > 0 && map[t][s - 1] == 0 && s != 6) {
		if (t != b || s - 1 != a) {
			s--;
		}
	}
	if (m == 2 && s < 11 && map[t][s + 1] == 0 && s != 5) {
		if (t != b || s + 1 != a) {
			s++;
		}
	}
	if (m == 3 && t < 11 && map[t + 1][s] == 0 && t != 5) {
		if (t + 1 != b || s != a) {
			t++;
		}
	}
}
void key_move()
{
	char key;
	int change = 0;
	key = getch();
	while (change == 0) // 상 72 하 80 좌 75 우 77
	{
		key = getch();
		if (key == 72 && y > 0 && map[y - 1][x] == 0) {
			y--;
			if (y == 5) {
				change++;
				if (x >= 0 && x < 6) {
					limit_3();
				}
				else {
					limit_4();
				}
			}
		}
		if (key == 80 && y < 11 && map[y + 1][x] == 0) {
			y++;
			if (y == 6) {
				change++;
				if (x >= 0 && x < 6) {
					limit_1();
				}
				else {
					limit_2();
				}
			}
		}
		if (key == 75 && x > 0 && map[y][x - 1] == 0) {
			x--;
			if (x == 5) {
				change++;
				if (y >= 0 && y < 6) {
					limit_2();
				}
				else {
					limit_4();
				}
			}
		}
		if (key == 77 && x < 11 && map[y][x + 1] == 0) {
			x++;
			if (x == 6) {
				change++;
				if (y >= 0 && y < 6) {
					limit_1();
				}
				else {
					limit_3();
				}
			}
		}
		if (y == b && x == a) {
			change++;
		}
		map_print();
		printf("Let's go home!\n");
	}
	if (y != b || x != a) {
		pointer();  change = 0;
	}
}
void move()
{
	while (y != b || x != a) {
		limit_home();
		person_move();
		pointer_move();
		Sleep(200);
		map_print();
		printf("Let's go home!\n");
		if (y == t && x == s)
		{
			key_move();
		}
	}
}