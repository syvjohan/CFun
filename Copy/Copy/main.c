#include <stdio.h>
#include <stdlib.h>

void copy1(char * const s1, char * const s2);
void copy2(char *s1, char *s2);

int main(void) {

	char string1[10];
	char *string2 = "Hello";
	char string3[10];
	char *string4 = "Good bye";

	copy1(string1, string2);
	printf("string1 = %s\n", string1);

	copy2(string3, string4);
	printf("string3 = %s\n", string3);

	system("pause");
	return 0;
}

void copy1(char * const s1, char * const s2) {
	int count;
	for (count = 0; (s1[count] = s2[count]) != '\0'; count++) {
		;
	}
}

void copy2(char *s1, char *s2) {
	for(; (*s1 = *s2) != '\0'; s1++, s2++) {
		;
	}
}
