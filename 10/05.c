#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool ace_low, royal_flush, straight, flush, four, three;
int pairs;

void read_cards(char hand[NUM_CARDS][2]);
bool check_duplicate(char rank, char suit, char hand[NUM_CARDS][2], int cards_read);
void analyze_hand(char hand[NUM_CARDS][2]);
void selection_sort(char arr[NUM_CARDS][2], int size);
void print_result(void);

int main(void)
{
	// Rank / Suit
	char hand[NUM_CARDS][2];

	for (;;) {
		read_cards(hand);
		analyze_hand(hand);
		print_result();
	}
}

void read_cards(char hand[NUM_CARDS][2])
{
	char ch, rank_ch, suit_ch;
	int rank, suit;
	bool bad_card;
	int cards_read = 0;

	while (cards_read < NUM_CARDS) {
		bad_card = false;

		printf("Enter a card: ");

		rank_ch = getchar();
		switch (rank_ch) {
			case '0': exit(EXIT_SUCCESS);
			case '2':		rank = 0; break;
			case '3':		rank = 1; break;
			case '4':		rank = 2; break;
			case '5':		rank = 3; break;
			case '6':		rank = 4; break;
			case '7':		rank = 5; break;
			case '8':		rank = 6; break;
			case '9':		rank = 7; break;
			case 't': case 'T':	rank = 8; break;
			case 'j': case 'J':	rank = 9; break;
			case 'q': case 'Q':	rank = 10; break;
			case 'k': case 'K':	rank = 11; break;
			case 'a': case 'A':	rank = 12; break;
			default:		bad_card = true;
		}

		suit_ch = getchar();
		switch (suit_ch) {
			case 'c': case 'C':	suit = 0; break;
			case 'd': case 'D':	suit = 1; break;
			case 'h': case 'H':	suit = 2; break;
			case 's': case 'S':	suit = 3; break;
			default:		bad_card = true;
		}

		while ((ch = getchar()) != '\n')
				if (ch != ' ') bad_card = true;

		if (bad_card)
			printf("Bad card; ignored.\n");
		else if (check_duplicate(rank_ch, suit_ch, hand, cards_read))
			printf("Duplicate card; ignored.\n");
		else {
			hand[cards_read][0] = rank;
			hand[cards_read][1] = suit;
			cards_read++;
		}
	}
}

bool check_duplicate(char rank, char suit, char hand[NUM_CARDS][2], int cards_read)
{
	for (int i = 0; i < cards_read; i++)
		if (hand[i][0] == rank && hand[i][1] == suit)
			return true;

	return false;
}

void analyze_hand(char hand[NUM_CARDS][2])
{
	ace_low = true;
	royal_flush = true;
	straight = true;
	flush = true;
	four = false;
	three = false;
	pairs = 0;

	selection_sort(hand, NUM_CARDS);

	// Check for royal_flush & flush
	for (int i = 0; i < NUM_CARDS-1; i++) {
		if (hand[i][1] != hand[i+1][1]) {
			flush = false;
			royal_flush = false;
			break;
		}
	}

	// Check for ace-low straight
	if (hand[NUM_CARDS-1][0] == 12)
		for (int i = 0; i < NUM_CARDS-1; i++) {
			if (hand[i][0] != 0 + i) {
				ace_low = false;
				break;
			}
		}

	// Check for straight && ace-low straight
	for (int i = 0; i < NUM_CARDS-1; i++) {
		if (hand[i][0] != 7 + (i + 1))
			royal_flush = false;
		if (hand[i][0] != (hand[i+1][0]) - 1) {
			straight = false;
			break;
		}
	}

	// Check for four-of-a-kind, three-of-a-kind, pairs
	for (int i = 0, match; i < NUM_CARDS; i++) {
		match = 0;
		for (int j = i + 1; j < NUM_CARDS; j++) {
			if (hand[j][0] == hand[i][0])
				match++;
		}

		if (match == 1) pairs++;
		if (match == 3) three = true;
		if (match == 4) four = true;
	}
}

void selection_sort(char arr[NUM_CARDS][2], int size)
{
	if (size == 1)
		return;

	int largest = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i][0] > arr[largest][0])
			largest = i;
	}

	int temp = arr[size-1][0];
	arr[size-1][0] = arr[largest][0];
	arr[largest][0] = temp;

	selection_sort(arr, size - 1);
}

void print_result(void)
{
	if (royal_flush)	printf("Royal flush");
	else if (straight &&
		flush)		printf("Straight flush");
	else if (four)		printf("Four of a kind");
	else if (three &&
		pairs == 1)	printf("Full house");
	else if (flush)		printf("Flush");
	else if (ace_low)	printf("Ace-low Straight");
	else if (straight)	printf("Straight");
	else if (three)		printf("Three of a kind");
	else if (pairs == 2)	printf("Two pairs");
	else if (pairs == 1)	printf("Pair");
	else			printf("High card");

	printf("\n\n");
}




