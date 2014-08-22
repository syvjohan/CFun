#include <stdio.h>
#include <stdlib.h>

#define SIZE 99

void mean( const int answer[]);
void median( int answer[]);
void mode(	int freq[], const int answer[]);
void bubbleSort(int arr[]);
void printArray( const int arr[]);

int main(void) {

	int frequency[10] = {0};

	int response[ SIZE ] =
		{ 
		6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
		7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
		6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
		7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
		6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
		7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
		5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
		7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
		7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
		4, 5, 6, 1, 6, 5, 7, 8, 7 
		};

	mean(response);
	median(response);
	mode(frequency, response);

	system("pause");
	return 0;
}

void mean(const int answer[]) {

	int count;
	int sum = 0;

	printf("%s\n%s\n%s\n", "********", " Mean", "********");

	for(count = 0; count < SIZE; count++) {
		sum += answer[count];
	}

	printf( "The mean is the average value of the data\n"
			"items. The mean is equal to the total of\n"
			 "all the data items divided by the number\n"
			 "of data items ( %d ). The mean value for\n"
			 "this run is: %d / %d = %.4f\n\n",
			 SIZE, sum, SIZE, ( double ) sum / SIZE 
			 );
}

void median( int answer[]) {

	printf( 
		"\n%s\n%s\n%s\n%s",
		"********", " Median", "********",
		"The unsorted array of responses is" 
		);

	printArray(answer);
	bubbleSort(answer);

	printf("\n\nThe sorted array is: \n");
	printArray(answer);

	printf( 
		"\n\nThe median is element %d of\n"
		"the sorted %d element array.\n"
		"For this run the median is %d\n\n",
		SIZE / 2, SIZE, answer[SIZE / 2] 
		);
}
