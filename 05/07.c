#include <stdio.h>

int main(void)
{
	int n1, n2, n3, n4, lOne, lTwo, sOne, sTwo, largest, smallest;

	printf("Enter four integers: ");
	scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

	if (n1 > n2) {
		lOne = n1;
		sOne = n2;
	} else {
		sOne = n1;
		lOne = n2;
	}

	if (n3 > n4) {
		lTwo = n3;
		sTwo = n4;
	} else {
		lTwo = n4;
		sTwo = n3;
	}

	if (lOne > lTwo) {
		largest = lOne;
	} else {
		largest = lTwo;
	}

	if (sOne < sTwo) {
		smallest = sOne;
	} else {
		smallest = sTwo;
	}

	printf("Largest: %d\n", largest);
	printf("Smallest: %d\n", smallest);

	return 0;
}
