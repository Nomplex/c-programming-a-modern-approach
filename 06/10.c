#include <stdio.h>

int main(void)
{
	int m, d, y, M = 0, D = 0, Y = 0;

	/* Could also just prompt user to enter M D Y here */

	while (1) {
		printf("Enter a date (mm/dd/yy): ");
		scanf("%d/%d/%d", &m, &d, &y);

		if (!m || !d || !y)
			break;

		if ((!M || !D || !Y) || y < Y || (y == Y && m < M) || (m == M && d < D)) {
			M = m;
			D = d;
			Y = y;
		}
	}
	
	printf("%d/%d/%.2d is the earliest date\n", M,D,Y);
	return 0;
}
