#include <stdio.h>

int main(void)
{
	int score;
	printf("Enter numerical grade: ");
	scanf("%d", &score);

	score /= 10;

	switch(score) {
		case 10:
		case 9:
			printf("Letter Grade: A\n");
			break;
		case 8:
			printf("Letter Grade: B\n");
			break;
		case 7:
			printf("Letter Grade: C\n");
			break;
		case 6:
			printf("Letter Grade: D\n");
			break;
		default:
			printf("Letter Grade: F\n");
	}

	return 0;
}
