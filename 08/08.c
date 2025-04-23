#include <stdio.h>

#define SIZE 5

int main(void)
{
	int quizStudent[SIZE][SIZE];
	
	for (int q = 0; q < SIZE; q++) {
		printf("Enter quiz %d scores: ", q + 1);
		for (int s = 0; s < SIZE; s++)
			scanf("%d", &quizStudent[q][s]);
	}

	printf("\tAverage\tHighscore\tLowscore\n");
	for (int q = 0; q < SIZE; q++) {
		int avg = 0, high = quizStudent[q][0], low = quizStudent[q][0];
		for (int s = 0; s < SIZE; s++) {
			avg += quizStudent[q][s];
			if (quizStudent[q][s] > high)
				high = quizStudent[q][s];
			if (quizStudent[q][s] < low)
				low = quizStudent[q][s];
		}
		printf("Quiz %d:\t%d\t%d\t%d\n", q + 1, avg / SIZE, high, low);
	}

	printf("\n\t\tTotal\tAverage\n");
	for (int s = 0; s < SIZE; s++) {
		int total = 0;
		for (int q = 0; q < SIZE; q++) {
			total += quizStudent[q][s];
		}
		printf("Student %d:\t%d\t%d\n", s + 1, total, total / SIZE);
	}

	printf("\n");
	return 0;
}
