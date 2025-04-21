#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char ch;
	int h, m, mFromMidnight;

	printf("Enter a 12 hour time (1:00pm): ");
	scanf("%d:%d %c", &h, &m, &ch);

	if (toupper(ch) == 'P')
		mFromMidnight = (12 + (h % 12)) * 60 + m;
	else
		mFromMidnight = (0 + (h % 12)) * 60 + m;

	// Could save these in variables.
	if (mFromMidnight < 8 * 60)
		printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
	else if (mFromMidnight < 9 * 60 + 43)
		printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
	else if (mFromMidnight < 11 * 60 + 19)
		printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
	else if (mFromMidnight < 12 * 60 + 47)
		printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
	else if (mFromMidnight < 14 * 60)
		printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
	else if (mFromMidnight < 15 * 60 + 45)
		printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
	else if (mFromMidnight < 19 * 60)
		printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
	else if (mFromMidnight < 21 * 60 + 45)
		printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
	else
		printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");

	return 0;
}
