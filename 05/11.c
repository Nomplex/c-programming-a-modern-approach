#include <stdio.h>

int main(void)
{
	int num, tens, ones;

	printf("Enter a two-digit number: ");
	scanf("%2d", &num);

	tens = num / 10;
	ones = num % 10;

	switch(tens) {
		case 1:
			if (ones == 0)
				printf("ten");
			break;
		case 2:
			printf("twenty");
			break;
		case 3:
			printf("thirty");
			break;
		case 4:
			printf("fourty");
			break;
		case 5:
			printf("fifty");
			break;
		case 6:
			printf("sixty");
			break;
		case 7:
			printf("seventy");
			break;
		case 8:
			printf("eighty");
			break;
		case 9:
			printf("ninety");
			break;
	}

	switch(ones) {
		case 1:
			if (tens == 1) printf("eleven");
			else printf("-one");
			break;
		case 2:
			if (tens == 1) printf("twelve");
			else printf("-two");
			break;
		case 3:
			if (tens == 1) printf("thirteen");
			else printf("-three");
			break;
		case 4:
			if (tens == 1) printf("fourteen");
			else printf("-four");
			break;
		case 5:
			if (tens == 1) printf("fifteen");
			else printf("-five");
			break;
		case 6:
			if (tens == 1) printf("sixteen");
			else printf("-six");
			break;
		case 7:
			if (tens == 1) printf("seventeen");
			else printf("-seven");
			break;
		case 8:
			if (tens == 1) printf("eighteen");
			else printf("-eight");
			break;
		case 9:
			if (tens == 1) printf("nineteen");
			else printf("-nine");
			break;
	}

	printf("\n");

	return 0;
}
