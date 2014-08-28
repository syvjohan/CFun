#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {

	/*char s1[17];
	char s2[] = "copy this string";

	memcpy(s1,s2, 13);

	printf("%s\n", s1);
	*/

	//printf("%s\n", strerror(1));
	
	char c = '\0';

	scanf("%c", &c);

	switch (c)
	{
	case 'a':
			printf("pppppp");
			break;
	default:
		break;
	}

	system("pause");
	return 0;
}