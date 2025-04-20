#include <stdio.h>

int main(void)
{
	int max;
	
	printf("Enter max square: ");
	scanf("%d", &max);

	for (int n = 1; n * n <= max; n++) {
		if ((n * n) % 2 == 0)
			printf("%d\n", n * n);
	}

	return 0;
}
