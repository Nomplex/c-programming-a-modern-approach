#include "split.h"

int *split(int *low, int *high)
{
	int part_element = *low;

	for (;;) {
		while (low < high && part_element <= *high)
			high--;
		if (low >= high) break;
		*low++ = *high;

		while (low < high && *low <= part_element)
			low++;
		if (low >= high) break;
		*high-- = *low;
	}

	*high = part_element;
	return high;
}
