#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
	int win = 0, loss = 0;
	char ch;

	srand((unsigned) time(NULL));

	do {
		play_game() ? win++ : loss++;
		printf("Play again? ");
		scanf(" %c", &ch);
		putchar('\n');
	} while(ch == 'Y' || ch == 'y');

	printf("\nWins: %d\tLosses: %d\n", win, loss);

	return 0;
}

int roll_dice(void)
{
	return (rand() % 6) + 1;
}

bool play_game(void)
{
	int roll, point;

	roll = roll_dice() + roll_dice();
	printf("You rolled: %d\n", roll);
	if (roll == 7 || roll == 11) {
		printf("You win!\n");
		return true;
	}

	if (roll == 2 || roll == 3 || roll == 12) {
		printf("You lose!\n");
		return false;
	}

	point = roll;
	printf("Your point is %d\n", point);
	
	for(;;) {
		roll = roll_dice() + roll_dice();
		printf("You rolled: %d\n", roll);

		if (roll == point) {
			printf("You win!\n");
			return true;
		}

		if (roll == 7) {
			printf("You lose!\n");
			return false;
		}
	}
}
