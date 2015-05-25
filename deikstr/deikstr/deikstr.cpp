// deikstr.cpp : Defines the entry point for the console application.
/**
*@file deikstr.cpp
*@version 1.1
*@title Release algoritym Deikstra
*/
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#define INT_MAX 2147483647
using namespace std;
/**
*@func Функция релизующая алгритм Дейкстры
*@param **A - указатель на матрицу смежности
*@param st - начальный узел
*@param N - размерность матрицы
*/
void Deikstra(int** A, int st, int N)
{
	int *dist, counter, index, i, u, m = st + 1;
	dist = new int[N];
	bool *visit;
	visit = new bool[N];

	for (i = 0; i<N; i++)
	{
		dist[i] = INT_MAX;
		visit[i] = false; /// Присваем расстояниям в начале "бесконечность" и узлам то что они не посещённые
	}

	dist[st] = 0; /// Метка 0 для начального узла

	for (counter = 0; counter<N - 1; counter++)/// Основной цикл
	{
		int min = INT_MAX;
		for (i = 0; i<N; i++)
			if (!visit[i] && dist[i] <= min)
			{
				min = dist[i]; index = i;
			}
		u = index;
		visit[u] = true;
		for (i = 0; i<N; i++)
			if (!visit[i] && A[u][i] && dist[u] != INT_MAX && dist[u] + A[u][i]<dist[i])
				dist[i] = dist[u] + A[u][i];
	}
	printf("Minimalnoe rasstojanie puti iz nachalnoi vershini do ostalnich:\n");
	for (i = 0; i<N; i++)
		if (dist[i] != INT_MAX)
			printf("iz %d v %d = %d\n", m, i + 1, dist[i]);
		else printf("%d v %d = error\n", m, i + 1);
}

int main()
{
	int uzel, N;
	printf("Vvedite kolichestvo uzlov: ");
	scanf_s("%d", &N);
	int **A;
	A = new int*[N];
	for (int i = 0; i<N; i++)
	{
		A[i] = new int[N];
	}
	printf_s("Pravila vvoda:\n 1. Vvodite rasstojanie ot odnogo uzla k drugomu\n 2. Esli ne sushestvuet puti to vvodite 0\n 3. Esli mojno idti ot uzla 'a' k 'b' b obratno to vvodite pri zadanii rasstojania v dvuch sluchajach odinnakovoe rasstojanie");
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			if (i == j)
			{
				printf_s("Rasstojanie iz uzla %d v %d = 0", i + 1, j + 1);
				A[i][j] = 0;
				puts("");
			}
			else
			{
				printf_s("Rasstojanie iz uzla %d v %d = ", i + 1, j + 1);
				scanf_s("%d", &A[i][j]);
			}

		}
		puts("");
	}
	printf_s("Poluchivshajasa matriza:\n");
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
			printf_s("%d ", A[i][j]);

		puts("");
	}
	printf_s("Vvedite nachalnauju vershinu - ");
	scanf_s("%d", &uzel);
	Deikstra(A, uzel - 1, N);
	_getch();
	return 0;
}
