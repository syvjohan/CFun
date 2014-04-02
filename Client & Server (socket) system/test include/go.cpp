#include "test.h"

// säger till kompilatorn att tolkas som extern c. Kod som är giltig i c men inte i cpp.
extern "C" { 
	#include <stdio.h>
}
//#include <cstdio>

int main() {
        int a = 2;
        int b = 3;
 
        printf("%d\n", add(a,b));
        return 0;
}

//http://lazyfoo.net/tutorials/SDL/index.php