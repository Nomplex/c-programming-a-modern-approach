#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 20

void reverse_name(char *name);

int main(void)
{
	char name[MAX + 1];
	printf("Enter a name: ");
	fgets(name, MAX, stdin);

	reverse_name(name);
	printf("%s\n", name);

	return 0;
}


void reverse_name(char *name)
{
	char fInit, *p = &name[0];
	// Remove White Space
	while (isspace(*name))
		name++;
	fInit = *name;
	while (!isspace(*name))
		name++;
	while (isspace(*name))
		name++;

	while (*name) {
		if(isspace(*name))
			break;
		*p = *name;
		name++;
		p++;
	}
	*p++ = ',';
	*p++ = ' ';
	*p++ = fInit;
	*p++ = '.';
	*p = '\0';
}
