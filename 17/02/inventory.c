#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include "inventory.h"
#include "quicksort.h"

int find_part(struct part *inventory, int *num_parts, int number);
void insert(struct part *inventory, int *num_parts);
void search(struct part *inventory, int *num_parts);
void update(struct part *inventory, int *num_parts);
void updatePrice(struct part *inventory, int *num_parts);
void print(struct part *inventory, int *num_parts);
void resize_array(struct part **inventory, int *current_max);
int compare_parts(const void *, const void *);

int main(void)
{
	char code;
	int current_max = 10, num_parts = 0;
	struct part *inventory = malloc(current_max * sizeof(struct part));
	if (!inventory)
		exit(EXIT_FAILURE);

	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n') // Skips to end of line
			;
		switch (code) {
			case 'i':
				if (num_parts == current_max) {
					printf("Database is full; doubling array size\n");
					resize_array(&inventory, &current_max);
				}
				insert(inventory, &num_parts);
				break;
			case 's': search(inventory, &num_parts);
				  break;
			case 'u': update(inventory, &num_parts);
				  break;
			case 'm': updatePrice(inventory, &num_parts);
				  break;
			case 'p': print(inventory, &num_parts);
				  break;
			case 'q': free(inventory);
				  return 0;
			default: printf("Illegal code\n");
		}
		printf("\n");
	}
}

int find_part(struct part inventory[], int *num_parts, int number)
{
	for (int i = 0; i < *num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

void insert(struct part inventory[], int *num_parts)
{
	int part_number;


	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(inventory, num_parts, part_number) >= 0) {
		printf("Part already exists.\n");
		return;
	}

	inventory[*num_parts].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[*num_parts].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[*num_parts].on_hand);
	printf("Enter price of part: ");
	scanf("%lf", &inventory[*num_parts].price);
	(*num_parts)++;
}

void search(struct part inventory[], int *num_parts)
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(inventory, num_parts, number);
	if (i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
		printf("Price of part: %.2f", inventory[i].price);
	} else
		printf("Part not found.\n");
}

void update(struct part inventory[], int *num_parts)
{
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(inventory, num_parts, number);
	if (i >= 0) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand = change;
	} else
		printf("Part not found.\n");
}

void updatePrice(struct part inventory[], int *num_parts) {
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(inventory, num_parts, number);
	if (i >= 0) {
		printf("Enter new price for part: ");
		scanf("%lf", &inventory[number].price);
	} else
		printf("Part not found.\n");
}

void print(struct part inventory[], int *num_parts)
{
	qsort(inventory, (size_t) *num_parts, sizeof(struct part), compare_parts);
	// quicksort(inventory, inventory + *num_parts - 1);
	printf("Part Number\tPart Name\tPart Price\tQuantity on Hand\n");
	for (int i = 0; i < *num_parts; i++)
		printf("%7d\t%-25s\t%.2f\t%11d\n", inventory[i].number, inventory[i].name, inventory[i].price, inventory[i].on_hand);
}

void resize_array(struct part **inventory, int *current_max)
{
	*current_max *= 2;
	*inventory = realloc(*inventory, *current_max * sizeof(struct part));
	if (*inventory == NULL)
		exit(EXIT_FAILURE);
}

int compare_parts(const void *p, const void *q) {
	const struct part *p1 = p;
	const struct part *p2 = q;

	return p1->number - p2->number;
}
