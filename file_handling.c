#include <stdlib.h>
#include <stdio.h>

int main()
{

	char sor[100];
	FILE *fp;
	fp = fopen("random_text.txt", "rt");

	if(fp == NULL)
	{	
		printf("Sikertelen megnyitas\n");
	}else
	{
		printf("Sikeres megynitas\n");
		while(fgets(sor,99, fp))
		{
			printf("%s\n", sor);
		}
	}

	
	

	int close = fclose(fp);

	if(close == 0)
	{
		printf("%s\n", "Sikeres lezaras");
	}else
	{
		printf("%s\n", "Sikertelen lezaras");
	}

 	return 0;
}