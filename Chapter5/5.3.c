#include <string.h>
#include <stdio.h>


void stringcpy(const char *source, char *dest) {
     while ( (*dest = *source) !=  '\0') {
         ++source;
         ++dest;
     }
}
 
int main() {
    char *sample = "MyString";
    char buffer[64];
 
    stringcpy(sample, buffer);
   
    printf("sample: %s\nbuffer: %s\n", sample, buffer);
 
    return 0;
}


