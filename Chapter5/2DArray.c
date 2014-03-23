#include <stdio.h>

//equivalent to int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
int arrYear[12][31] = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16},
	{17,18,19,20}
};

int main() {
	int i, j;
 
   /* output each array element's value */
   for ( i = 0; i < 3; i++ )
   {
      for ( j = 0; j < 4; j++ )
      {
         printf("a[%d][%d] = %d\n", i,j, arrYear[i][j] );
      }
   }
   return 0;
}