#define _CRT_SECURE_NO_WARNINGS
#define _CTR_NONSTDC_NO_WARNINGS
#include "stdafx.h"
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <random>
#include <malloc.h>
#include <locale>
#include <queue>
using namespace std;

void bfs(int v, int **mat, int *vershins, int m) {
	queue<int> q;
	q.push(v);
	vershins[v] = 0;
	while(!q.empty()){
		v = q.front();
		q.pop();
		printf("%d ", v);
	for (int i = 0; i < m; i++)
	{
		if (mat[v][i] == 1 && vershins[i] == -1)
		{
			q.push(i);
			vershins[i] = vershins[v] + 1;
		}
	}
	}
}
int main()
{

	int **mat;
	int *vershins;
	int m;
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	printf("input size: ");
	scanf_s("%d", &m);
	mat = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		mat[i] = (int*)malloc(m * sizeof(int));
	}
	vershins = (int*)malloc(m * sizeof(int));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
				mat[i][j] = rand() % 2;
			
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf(" %4d", mat[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < m; i++) {
		vershins[i] = -1;
	}
	int v;
	printf("input vershin: ");
	scanf_s("%d",  &v);
	bfs(v, mat, vershins, m);
	for (int i = 0; i < m; i++){
		printf(" %4d", vershins[i]);}


	getchar();
	getchar();
	return 0;

}
