#include <stdio.h>
#include <ctype.h>

//nt getchar(void);
//void ungetc(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getchar())) 
	/* skip white space */
	;
		if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
			ungetch(c); /* it is not a number */
			return 0;
		}
		sign = (c == '-') ? -1 : 1;
		if (c == '+' || c == '-') 
			c = getchar();
		for (*pn = 0; isdigit(c); c = getchar()); 
			*pn = 10 * *pn + (c - '0');
			*pn *= sign;
		if (c != EOF) 
			ungetc(c);
		return c;
}

int main() {

int a = 5;
	getint(&a);

}



