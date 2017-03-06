#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void foglal(int*** ptomb, int magas, int szeles)
{
	int** uj;
	int i,j;
	uj = (int**)malloc(magas * sizeof(int*));
	for(i = 0; i < magas ; i++)
	{
		uj[i] = (int*)malloc(szeles * sizeof(int));
		for(j = 0; j < szeles; j++)
		{
			uj[i][j] = i +j;
		}
	}
	*ptomb = uj;
}

int main()
{
	int** ptomb;
	foglal(&ptomb, SIZE,SIZE);
	int i,j;
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			printf("%d ", ptomb[i][j]);
		}
		printf("\n");
	}
	free(ptomb);
}