#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 10
char buf[BUFSIZE];
char *bufp = buf;

int getch(void){
	return ((bufp>buf) ? *(--bufp) : getchar());
}

void ungetch(int c){
	if (bufp >= buf + BUFSIZE)
		printf("\n Ungetch: Too many characters!\n");
	else *bufp++ = c;
}


int getint(int *p){

	int c, sign, ok;
	c = 0; ok = 0;
	while (!ok && c != EOF){
		while ((c = getch()) == ' ' || c == '\n' || c == '\t');
		sign = 1;
		if (c == '+' || c == '-'){
			sign = (c == '+') ? 1 : -1;
			c = getch();
		}
		for (*p = 0; c >= '0' && c <= '9'; c = getch()){
			//for(*p=0;isdecimal(c);c=getch())  ctype.h

			*p = 10 * (*p) + c - '0';
			ok = 1;

		}
		*p *= sign;
		while (c != ' ' && c != '\n' && c != '\t'){
			c = getch();
			ok = 0;
		}
		if (!ok)
			printf("Error, please try again!\n");
	}
	if (c != EOF)
		ungetch(c);

	return (c);
}

int main(int argc ,char* argv[])
{
	int* num = (int*)calloc(sizeof(int),0);
	
	printf("Please enter a number: ");
	
	getint(num);
	
	printf("The number you entered: %d", *num);
	
	return 0;
}