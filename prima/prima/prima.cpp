// prima.cpp : Defines the entry point for the console application.
//
/**
*@file prima.cpp
*@version 1.1
*@title Release algoritym prima
*/
#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#define INT_MAX 2147483646
using namespace std;

int main()
{
	int N;
	printf("Vvedite kolichestvo uzlov: ");
	scanf("%d", &N);
	int **A = new int*[N];
	for (int i = 0; i<N; i++)
	{
		A[i] = new int[N];
	}
	int *Visit = new int[N];
	printf("Vvedite matrizu smejnosti\n");
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			if (i == j)
			{
				A[i][j] = 0;
			}
			if (i<j)
			{
				printf("Rasstojanie ot %d do %d: ", i + 1, j + 1);
				scanf("%d", &A[i][j]);
				A[j][i] = A[i][j];
			}
		}
	}
	printf("Poluchivsheesja matriza smejnosti");
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			printf("%d ", A[i][j]);
			if (A[i][j] == 0)
			{
				A[i][j] = INT_MAX;
			}
		}
		puts("");
	}
	for (int i = 0; i<N; i++)
	{
		Visit[i] = 0;
	}
	Visit[0] = 1;
	int a, a1, b, b1, index1 = 0, index2 = 1, mincost = 0, min;
	while (index2 != N)
	{
		min = INT_MAX;
		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j<N; j++)
			{
				if (A[i][j]<min)
				{
					if (Visit[i] != 0)
					{
						min = A[i][j];
						a = a1 = i;
						b = b1 = j;
					}
				}
			}
		}
		if (Visit[a] == 0 || Visit[b] == 0)
		{
			printf("Minimalnoe rebro mejdu %d i %d: %d\n", ++a1, ++b1, min);
			Visit[b] = 1;
			index2++;
			mincost += min;
		}
		A[a][b] = A[b][a] = INT_MAX;
	}
	printf("Minimalnaja stoimost poluchivchegosa ostovnogo dereva: %d", mincost);
	getch();
	return 0;
}

