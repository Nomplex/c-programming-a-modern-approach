#include "quicksort.h"
#include "split.h"

void quicksort(int *low, int *high)
{
	int *middle;

	if (low > high) return;
	middle = split(low, high);
	quicksort(low, middle - 1);
	quicksort(middle + 1, high);
}
