// Inventory has to come first.
// Would including it in the quicksort header be better?
#include "inventory.h"
#include "quicksort.h"

void quicksort(struct part *low, struct part *high)
{
	struct part *middle;

	if (low > high) return;
	middle = split(low, high);
	quicksort(low, middle - 1);
	quicksort(middle + 1, high);
}

struct part *split(struct part *low, struct part *high)
{
	struct part part_element = *low;

	for (;;) {
		while (low < high && part_element.number <= (*high).number)
			high--;
		if (low >= high) break;
		*low++ = *high;

		while (low < high && (*low).number <= part_element.number)
			low++;
		if (low >= high) break;
		*high-- = *low;
	}

	*high = part_element;
	return high;
}
