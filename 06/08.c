#include <stdio.h>

int main(void)
{
	int totalDays, startingDay, currentDay;
	printf("Enter number of days in month: ");
	scanf("%d", &totalDays);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &startingDay);

	for (currentDay = 1; currentDay < startingDay; currentDay++) {
		printf("   ");
	}

	for (int i = 1; i <= totalDays; i++) {
		printf("%3d", i);
		if (currentDay % 7 == 0)
			printf("\n");
		currentDay++;
	}

	printf("\n");
	return 0;
}
