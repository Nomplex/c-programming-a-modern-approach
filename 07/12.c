#include <stdio.h>

int main(void)
{
	char ch;
	float f, total = 0;

	printf("Enter an expression: ");
	scanf("%f", &f);
	total += f;
	while ((ch = getchar()) != '\n') {
		switch (ch) {
			case '+':
				scanf("%f", &f);
				total += f;
				break;
			case '-':
				scanf("%f", &f);
				total -= f;
				break;
			case '*':
				scanf("%f", &f);
				total *= f;
				break;
			case '/':
				scanf("%f", &f);
				total /= f;
				break;
			default:
				printf("Invalid Operator\n");
				return 1;
		}
	}

	printf("Value of expression: %.2f\n", total);
	return 0;
}
