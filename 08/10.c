
#include <stdio.h>

int main(void)
{
	int dTimes[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
	int aTimes[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
	int h, m, mFromMidnight, i;
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &h, &m);

	mFromMidnight = h * 60 + m;

	for (i = 0; i < 8; i++) {
		if (mFromMidnight < dTimes[i])
			break;
	}

	printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
		dTimes[i] / 60 % 12, dTimes[i] % 60, dTimes[i] / 60 > 12 ? 'p' : 'a',
		aTimes[i] / 60 % 12, aTimes[i] % 60, aTimes[i]  / 60 > 12 ? 'p' : 'a');

	return 0;
}
