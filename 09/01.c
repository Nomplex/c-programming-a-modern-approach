#include <stdio.h>

void selection_sort(int arr[], int size);

int main(void)
{
	int arr[10];

	printf("Enter a series of integers: ");
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);

	selection_sort(arr, 10);

	printf("Sorted Array:");
	for (int i = 0; i < 10; i++)
		printf(" %d", arr[i]);

	printf("\n");
	return 0;
}

void selection_sort(int arr[], int size)
{
	if (size == 1)
		return;

	int largest = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > arr[largest])
			largest = i;
	}

	int temp = arr[size-1];
	arr[size-1] = arr[largest];
	arr[largest] = temp;

	selection_sort(arr, size - 1);
}
