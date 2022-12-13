#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

typedef struct rally
{
	int zhrebi;
	char* name;
	int ochki;
	int hours[4];
	int minutes[4];
	float seconds[4];
	int place;
	float cash;
};

struct rally zero(struct rally array, int j)
{

	array.zhrebi = j + 1;
	array.name = " ";
	for (int i = 0; i < 4; i++) 
	{
		array.seconds[i] = 0;
		array.minutes[i] = 0;
		array.hours[i] = 0;
	}
	array.ochki = 15;
	return array;
}

struct rally ok(struct rally array, int j)
{
	array.zhrebi = j + 1;
	array.name = "Test";
	for (int i = 0; i < 4; i++) 
	{
		array.seconds[i] = 0 + rand() % 60;
		array.minutes[i] = 0 + rand() % 60;
		array.hours[i] = 0 + rand() % 4;
	}
	array.ochki = 0;
	return array;
}

int time_s(struct rally array)
{
	array.cash = (array.hours[3] * 60 * 60) + (array.minutes[3] * 60) + array.seconds[3];
	return array.cash;
}

void SP(struct rally build[], int N)
{
	struct rally tmp;

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (time_s(build[j]) > time_s(build[j + 1]))
			{
				tmp = build[j];
				build[j] = build[j + 1];
				build[j + 1] = tmp;
			}
		}
	}

	return build;
}
void main() 
{
	char fname_2[20];
	char text[5] = ".txt";
	char name[20];
	char cash[20];
	FILE* file;
	int count, n, selection, selection_2, end;
	struct rally build[100];

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	n = 0;
	end = 0;
	printf("Введите кол-во участвующих команд: ");
	scanf_s("%d", &n);
	for (int k = 0; k < n; k++) 
	{
		build[k] = ok(build[k], k);
	}
	while (1)
	{
		count = 0;

		for (int i = 0; i < n; i++) 
		{
			int seconds_int;

			build[i].hours[3] = build[i].hours[0] + build[i].hours[1] + build[i].hours[2];
			build[i].minutes[3] = build[i].minutes[0] + build[i].minutes[1] + build[i].minutes[2];
			build[i].seconds[3] = build[i].seconds[0] + build[i].seconds[1] + build[i].seconds[2];

			seconds_int = build[i].seconds[3];
			if (seconds_int > 60) 
			{
				seconds_int -= 60;
				build[i].seconds[3] -= 60;
				build[i].minutes[3] += 1;
			}
			if (build[i].minutes[3] > 60)
			{
				build[i].minutes[3] -= 60;
				build[i].hours[3] += 1;
			}
		}
		system("cls");
		SP(build, n);
		printf("Программа результатов матчей на основе структур.\n");
		printf("Введите функцию:\n");
		printf("1. Показать таблицу.\n2. Изменить игроков.\n3. Загрузить результаты игроков из файла.\n4. Сохранить файл с результатами игроков.\n\n");
		printf("Введите действие: ");
		scanf_s("%d", &selection);
		system("cls");
		switch (selection) 
		{
		case 1: 
		{
			printf("========================================================================================================\n");
			printf("|%6s|%17s|%12s|%12s|%12s|%12s|%12s|%12s|\n", "Жребий", "ФИО", "1-Заезд", "2-Заезд", "3-Заезд", "Кол-во очков", "Общее время", "Место");
			printf("========================================================================================================\n");
			for (int i = 0; i < n; i++) 
			{
				printf("|%6d|", build[i].zhrebi);
				printf("|%16s|", build[i].name);
				printf("|%3d:%2d:%4.1f|", build[i].hours[0], build[i].minutes[0], build[i].seconds[0]);
				printf("|%3d:%2d:%4.1f|", build[i].hours[1], build[i].minutes[1], build[i].seconds[1]);
				printf("|%3d:%2d:%4.1f|", build[i].hours[2], build[i].minutes[2], build[i].seconds[2]);
				printf("|%11d|", n - i);
				printf("|%3d:%2d:%4.1f|", build[i].hours[3], build[i].minutes[3], build[i].seconds[3]);
				printf("|%11d|", i + 1);
				printf("\n");

			}
			printf("========================================================================================================\n");
			printf("\n\n");
			printf("Завершить программу?\n1. Да\n2. Нет\n");
			printf("Введите команду: ");
			scanf_s("%d", &end);
			printf("\n\n");
			system("cls");
			break;
		}
		case 2: 
		{
			printf("Введите подфункицию:\n");
			printf("1. Изменить название команды.\n2. Изменить время первого заезда гонщика.\n3. Изменить время второго заезда гонщика.\n4. Изменить время третьего заезда гонщика.\n");
			printf("Введите функцию: ");
			scanf_s("%d", &selection_2);
			system("cls");
			printf("Введите номер команды: ");
			scanf_s("%d", &selection);
			printf("\n");
			system("cls");
			switch (selection_2)
			{
			case 1:
			{
				printf("Введите название команды: ");
				scanf_s("%s", cash);
				build[(selection - 1)].name = cash;
				system("cls");
				break;
			}
			case 2:
			{
				printf("Введите секунды: ");
				scanf_s("%f", &build[(selection - 1)].seconds[0]);
				printf("\n");
				printf("Введите минуты: ");
				scanf_s("%d", &build[(selection - 1)].minutes[0]);
				printf("\n");
				printf("Введите часы: ");
				scanf_s("%d", &build[(selection - 1)].hours[0]);
				printf("\n");
				system("cls");
				break;
			}
			case 3:
			{
				printf("Введите секунды: ");
				scanf_s("%f", &build[(selection - 1)].seconds[1]);
				printf("\n");
				printf("Введите минуты: ");
				scanf_s("%d", &build[(selection - 1)].minutes[1]);
				printf("\n");
				printf("Введите часы: ");
				scanf_s("%d", &build[(selection - 1)].hours[1]);
				printf("\n");
				system("cls");
				break;
			}
			case 4:
			{
				printf("Введите секунды: ");
				scanf_s("%f", &build[(selection - 1)].seconds[2]);
				printf("\n");
				printf("Введите минуты: ");
				scanf_s("%d", &build[(selection - 1)].minutes[2]);
				printf("\n");
				printf("Введите часы: ");
				scanf_s("%d", &build[(selection - 1)].hours[2]);
				printf("\n");
				system("cls");
				break;
			}
			}
			break;
		}
		case 3:
		{
			printf("Введите название файла, с которого хотите прочитать результаты: ");
			scanf_s("%s", fname_2);
			strcat(fname_2, text);
			file = fopen(fname_2, "r");
			while (fscanf(file, "%s%d%d%d%f%d%d%f%d%d%f", name, &(build[count].zhrebi), &(build[count].hours[0]), &(build[count].minutes[0]), &(build[count].seconds[0]), &(build[count].hours[1]), &(build[count].minutes[1]), &(build[count].seconds[1]), &(build[count].hours[2]), &(build[count].minutes[2]), &(build[count].seconds[2])) != EOF)
			{
				build[count].name = name;
				printf("%s %d %d %d %.2f %d %d %.2f %d %d %.2f\n", build[count].name, (build[count].zhrebi), (build[count].hours[0]), (build[count].minutes[0]), (build[count].seconds[0]), (build[count].hours[1]), (build[count].minutes[1]), (build[count].seconds[1]), (build[count].hours[2]), (build[count].minutes[2]), (build[count].seconds[2]));
				count++;
			}
			n = count;
			fclose(file);
			break;
		}
		case 4:
		{
			printf("Введите название файла: ");
			scanf_s("%s", fname_2);
			strcat(fname_2, text);
			file = fopen(fname_2, "w");
			for (int i = 0; i < n; i++)
			{
				fprintf(file, "%s %d %d %d %.2f %d %d %.2f %d %d %.2f\n", build[i].name, (build[i].zhrebi), (build[i].hours[0]), (build[i].minutes[0]), (build[i].seconds[0]), (build[i].hours[1]), (build[i].minutes[1]), (build[i].seconds[1]), (build[i].hours[2]), (build[i].minutes[2]), (build[i].seconds[2]));
			}
			fclose(file);
			break;
		}
		default:
		{
			printf("Неправильно введена функция.");
			printf("\n\n");
			printf("Завершить программу?\n1) Да\n2) Нет\n");
			printf("Введите команду: ");
			scanf_s("%d", &end);
			system("cls");
			break;
		}
		}
		if (end == 1) 
		{
			break;
		}
	}
	return 0;



}