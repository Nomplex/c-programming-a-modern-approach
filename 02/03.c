#include <stdio.h>

int main(void)
{
	float v;
	int r;
	printf("Enter the radius of the sphere: ");
	scanf("%d", &r);
	v = 4.0f / 3.0f * 3.14159 * (r * r * r);
	printf("%.2f", v);

	return 0;
}
