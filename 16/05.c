#include <stdio.h>

struct departure_time {
	int dTime;
	int aTime;
};

int main(void)
{
	struct departure_time schedule[] = 
		{{480, 616}, {583, 712}, {679, 811}, {767, 900},
		{840, 968}, {945, 1075}, {1140, 1280}, {1305, 1438}};

	// int dTimes[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
	// int aTimes[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
	
	int h, m, mFromMidnight, i;
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &h, &m);

	mFromMidnight = h * 60 + m;

	for (i = 0; (unsigned) i < sizeof(schedule) / sizeof(schedule[0]); i++) {
		if (mFromMidnight < schedule[i].dTime)
			break;
	}
	i = i > (int) (sizeof(schedule) / sizeof(schedule[0])) ? 0 : i;

	printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
		schedule[i].dTime / 60 % 12,
		schedule[i].dTime % 60,
		schedule[i].dTime / 60 > 12 ? 'p' : 'a',
		schedule[i].aTime / 60 % 12,
		schedule[i].aTime % 60,
		schedule[i].aTime  / 60 > 12 ? 'p' : 'a');

	return 0;
}
