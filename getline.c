#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int getline(char *s, int lim)
{
	int c;
	char *t = s;

	while(lim-- > 0 && (c = getchar()) != EOF && c != '\n')
	{
		*t++ = c;
	}
	*t = '\0';

	while(c != EOF && c != '\n')
	{
		c = getchar();
	}

	return (t-s);
}

int main()
{
	char* s = (char*)malloc(SIZE * sizeof(char));

	int length = getline(s,SIZE);

	printf("%s \n size: %d\n", s, (length*sizeof(char)));

	free(s);

	return 0;
}