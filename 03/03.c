#include <stdio.h>

int main(void)
{
	int gs1, groupId, pubCode, itemNum, check;
	printf("Enter ISBN: ");
	scanf("%d-%d-%d-%d-%d", &gs1, &groupId, &pubCode, &itemNum, &check);

	/* I guess I could combine all these into one printf */
	printf("GS1 prefix: %d\n", gs1);
	printf("Group identifier: %d\n", groupId);
	printf("Publisher code: %d\n", pubCode);
	printf("Item number: %d\n", itemNum);
	printf("Check digit: %d\n", check);

	return 0;
}
