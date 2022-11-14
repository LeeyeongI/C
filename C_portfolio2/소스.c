#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


int map[10][10][10] = { 0 };
int i, j, k;
int second = 0, interval = 0; // second = ���� ������ �ð�, interval = ���� ������ ����
int x[5] = { 0 }, y[5] = { 0 }; // ���� ������ ��ġ x,y���� �޴� ����
int count = 0; // �¿�Ű�� �Է��� �޾� ���� �����ϴ� ����
int z = 0;// z���� �����ϴ� ����
char key; // �¿�Ű, �����̽��ٸ� �Է¹޴� ����


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


void start()// �����Ҷ� ���� ������ �ð��� ������ �����ϴ� �Լ�
{
	system("cls");
	printf("���� ������ �ð��� �������ּ���.(������ �Է����ּ���) ");
	scanf("%d", &second);
	printf("���� ������ ������ �������ּ���.(Sleep) ");
	scanf("%d", &interval);
	system("cls");
}
void screen()// �ʱ�ȭ������ ���ư� ���� ������ �ð��� ������ �����ϰų� ���α׷��� �����ϴ� �Լ�
{
	int q = 0;
	system("cls");
	printf("1.���� �� ���� �;��.\n2.���� �׸� ������.\n");
	scanf("%d", &q);
	while (q != 1 && q != 2)
	{
		system("cls");
		printf("�ٽ� �Է����ּ���.\n");
		printf("1.���� �� ���� �;��.\n2.���� �׸� ������.\n");
		scanf("%d", &q);
	}
	if (q == 1)
	{
		system("cls");
		printf("���� ������ �ð��� �������ּ���.(������ �Է����ּ���) ");
		scanf("%d", &second);
		printf("���� ������ ������ �������ּ���.(Sleep) ");
		scanf("%d", &interval);
		system("cls");
		snowing();
	}
	else if (q == 2)
	{
		system("cls");
		printf("\t�š�š�š�š��\n\t�š�š�š�š��\n\t�š��š��š��š���\n");
		printf("\t MERRY CHRISTMAS!!\n");
	}
}
void map_print_top()//���� ������ ������ִ� �Լ�
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
			if (map[9][j][k] == 1) printf("��");
			else if (map[9][j][k] == 0) printf("��");
		}
		printf("\n");
	}
	printf("[����]\n");
	printf("\n");
	new_snow();
}
void map_print_front()//���� ������ ������ִ� �Լ�
{

	for (i = 0; i < 5; i++)
	{
		map[z][9][x[i]] = 1;
	}
	for (i = 9; i >= 0; i--)
	{
		for (k = 0; k < 10; k++)
		{
			if (map[i][9][k] == 1) printf("��");
			else if (map[i][9][k] == 0)	printf("��");
		}
		printf("\n");
	}
	printf("[����]\n");
	new_snow();
}
int random()// ���� ��ġ�� �������� �����ϱ� ���� ��ǥ���� �޴� �Լ�
{
	int r = 0;
	r = rand() % 10;
	return r;
}
void new_snow() // map �迭�� �ʱ�ȭ ���ִ� �Լ�
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
void snow_pst()//���� ��ǥ���� �޴� �Լ�
{
	new_snow();
	for (i = 0; i < 5; i++)
	{
		x[i] = random();
		y[i] = random();
	}
	z = 9;
}
void map_print_right() //���� �����ʸ��� ����ϴ� �Լ�
{
	for (i = 0; i < 5; i++)
	{
		map[z][y[i]][9] = 1;
	}
	for (i = 9; i >= 0; i--)
	{
		for (j = 9; j >= 0; j--)
		{
			if (map[i][j][9] == 1) printf("��");
			else if (map[i][j][9] == 0)	printf("��");
		}
		printf("\n");
	}
	printf("[������]\n");
	new_snow();
}
void map_print_back()//���� �޸��� ����ϴ� �Լ�
{
	for (i = 0; i < 5; i++)
	{
		map[z][0][x[i]] = 1;
	}
	for (i = 9; i >= 0; i--)
	{
		for (k = 9; k >= 0; k--)
		{
			if (map[i][0][k] == 1) printf("��");
			else if (map[i][0][k] == 0)	printf("��");
		}
		printf("\n");
	}
	printf("[�޸�]\n");
	new_snow();
}
void map_print_left()//���� ���ʸ��� ����ϴ� �Լ�
{
	for (i = 0; i < 5; i++)
	{
		map[z][y[i]][0] = 1;
	}
	for (i = 9; i >= 0; i--)
	{
		for (j = 0; j < 10; j++)
		{
			if (map[i][j][0] == 1) printf("��");
			else if (map[i][j][0] == 0)	printf("��");
		}
		printf("\n");
	}
	printf("[����]\n");
	new_snow();
}
void map_turn() // ���� �� �����ڿ� �¿�Ű�� �̿��� ȭ���� �̵��ϴ� �Լ�
{
	printf("\n�����̽��ٸ� �����ø� �ʱ�ȭ������ ���ư� �� �ֽ��ϴ�.(�ʱ�ȭ�鿡�� ������ ����)\n");
	printf("�¿�Ű�� �̿��� ȭ���� �̵��� �� �ֽ��ϴ�.\n");
	key = _getch(); // �����̽��� 32 �� 75 �� 77
	while (key != 32)
	{
		if (key == 77) count++;
		if (key == 75) count--;
		if (count == 4) count = 0;
		if (count == -1) count = 3;

		if (count == 0) //count�� 0�϶� ���� ���
		{
			system("cls");
			map_print_top();
			map_print_front();
		}
		else if (count == 1) //count�� 1�϶� �����ʸ� ���
		{
			system("cls");
			map_print_top();
			map_print_right();
		}
		else if (count == 2) //count�� 2�϶� �޸� ���
		{
			system("cls");
			map_print_top();
			map_print_back();
		}
		else if (count == 3) //count�� 3�϶� ���ʸ� ���
		{
			system("cls");
			map_print_top();
			map_print_left();
		}
		printf("\n�����̽��ٸ� �����ø� �ʱ�ȭ������ ���ư� �� �ֽ��ϴ�.(�ʱ�ȭ�鿡�� ������ ����)\n");
		printf("�¿�Ű�� �̿��� ȭ���� �̵��� �� �ֽ��ϴ�.\n");
		key = _getch();
	}
	count = 0;
	screen();
}
void snow() // ���� ������ �̿��� �Լ�
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
void snowing() //���� ������ �Լ�
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