#include <stdio.h>

int main(void)
{
	int m1, m2, d1, d2, y1, y2;
	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &m1, &d1, &y1);

	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &m2, &d2, &y2);

	if (y1 < y2)
		printf("%d/%d/%d is earlier than %d/%d/%d", m1,d1,y1,m2,d2,y2);
	else if (y2 < y1)
		printf("%d/%d/%d is earlier than %d/%d/%d", m2,d2,y2,m1,d1,y1);
	else if (m1 < m2)
		printf("%d/%d/%d is earlier than %d/%d/%d", m1,d1,y1,m2,d2,y2);
	else if (m2 < m1)
		printf("%d/%d/%d is earlier than %d/%d/%d", m2,d2,y2,m1,d1,y1);
	else if (d1 < d2)
		printf("%d/%d/%d is earlier than %d/%d/%d", m1,d1,y1,m2,d2,y2);
	else if (d2 < d1)
		printf("%d/%d/%d is earlier than %d/%d/%d", m2,d2,y2,m1,d1,y1);
	else
		printf("They're the same date!");

	return 0;
}
