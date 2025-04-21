#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char ch;
	int h, m;
	
	printf("Enter a 12-hour time (1:00pm or 1:00 PM): ");
	scanf("%d:%d %c", &h, &m, &ch);

	if (toupper(ch) == 'P') {
		h = 12 + (h % 12);
	} else {
		h = 0 + (h % 12);
	}

	printf("Equivalent 24-hour time: %.2d:%.2d\n", h, m);
	return 0;
}
