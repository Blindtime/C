#include <stdio.h>
#include <stdlib.h>

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
	foglal(&ptomb, 10,10);
	int i,j;
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			printf("%d ", ptomb[i][j]);
		}
		printf("\n");
	}
	free(ptomb);
}