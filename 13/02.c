#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
	char reminders[MAX_REMIND][MSG_LEN+3];
	char day_str[12], msg_str[MSG_LEN+1];
	int month, day, i, j, num_remind = 0, h, m;

	for (;;) {
		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter date (mm/dd), 24 hour time (hh:mm), and reminder: ");
		scanf(" %2d/ %2d", &month, &day);
		if (day == 0 || month == 0)
			break;
		scanf(" %2d: %2d", &h, &m);
		sprintf(day_str, "%2.2d/%2.2d %2.2d:%2.2d", month, day, h, m);
		read_line(msg_str, MSG_LEN);

		if (month > 12 || month < 0 || day < 0 || day > 31
		|| h > 23 || h < 0 || m > 59 || m < 0) {
			printf("-- ERROR: Impossible Date --\n\n");
			continue;
		}

		for (i = 0; i < num_remind; i++)
			if (strcmp(day_str, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j-1]);

		strcpy(reminders[i], day_str);
		strcat(reminders[i], msg_str);

		num_remind++;
	}

	printf("\nDay Time  Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
