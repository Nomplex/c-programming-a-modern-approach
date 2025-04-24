#include <stdio.h>

int power(int n, int p);


int main(void)
{
	int n, p;

	printf("Enter a number: ");
	scanf("%d", &n);

	printf("Raise %d to the power of: ", n);
	scanf("%d", &p);

	printf("%d^%d = %d\n", n, p, power(n, p));
	return 0;
}

int power(int n, int p)
{
	int i;

	if (p == 0)
		return 1;
	if (n % 2 == 0) {
		i = power(n, p / 2);
		return i * i; 
	} else
		return n * power(n, p - 1);
}
