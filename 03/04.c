#include <stdio.h>

int main(void)
{
	int area, firstThree, lastFour;

	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	scanf("(%d) %d-%d", &area, &firstThree, &lastFour);

	printf("You entered %d.%d.%d", area, firstThree, lastFour);

	return 0;
}
