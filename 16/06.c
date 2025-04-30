#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
};

int compare_dates(struct date d1, struct date d2);

int main(void)
{
	int result;
	struct date d1, d2;
	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);

	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

	result = compare_dates(d1, d2);

	if (result == 1)
		printf("%d/%d/%d is earlier than %d/%d/%d\n", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
	else if (result == -1)
		printf("%d/%d/%d is earlier than %d/%d/%d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
	else
		printf("They're the same date!\n");

	return 0;
}

int compare_dates(struct date d1, struct date d2)
{
	if (d1.year - d2.year != 0)
		return (d1.year > d2.year) - (d1.year < d2.year);
	else if(d1.month - d2.month != 0)
		return (d1.month > d2.month) - (d1.month < d2.month);
	else
		return (d1.day > d2.day) - (d1.day < d2.day);
}
