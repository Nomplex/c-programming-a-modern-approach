#include <stdio.h>

int main(void)
{
	int h, m;

	printf("Enter a 24-hour time (hh:mm): ");
	scanf("%2d:%2d", &h, &m);

	printf("Equivalent 12-hour time: %d:%.2d ", h % 12 == 0 ? 12 : h % 12, m);
	if (h < 12)
		printf("AM");
	else
		printf("PM");

	return 0;
}
