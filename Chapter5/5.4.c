#include <string.h>


int stringend(char *s, char *t)
{
    char tmps = *s;
    char tmpt = *t;
    while(*s)
        s++;
    while(*t)
        t++;
    while(*s == *t)
    {
        if(*s == tmps || *t == tmpt)
            break;
        s--;
        t--;
    }
    if(*s == *t && *t == tmpt && *s != '\0')
        return 1;
    else
        return 0;
}

int main() {
    char *firstSample = "firstSample";
    char *secondSample = "secondSample";

    if (stringend(firstSample, secondSample)) {
        printf("Return 1 %s\n");
    }
    else {
        printf("Return 0 %s\n");
    }
}

//Write the function strend(s,t) , which returns 1 if the 
//string t occurs at the
//end of the string s , and zero otherwise.