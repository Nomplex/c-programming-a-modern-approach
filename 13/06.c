#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

bool compare_string(const char *str1, const char *str2);

int main(int argc, char *argv[])
{
	char *planets[] = {
		"Mercury", "Venus", "Earth",
		"Mars", "Jupiter", "Saturn",
		"Uranus", "Neptune", "Pluto"
	};

	for (int i = 1; i < argc; i++) {
		for (int j = 0; j < NUM_PLANETS; j++) {
			// On a posix compliant system I could use strcasecmp
			if (compare_string(argv[i], planets[j])) {
				printf("%s is planet %d\n", argv[i], j + 1);
				break;
			} else if (j + 1 == NUM_PLANETS) {
				printf("%s is not a planet\n", argv[i]);
			}
		}
	}

	return 0;
}

bool compare_string(const char *str1, const char *str2)
{
	while (*str1 && *str2) {
		if (toupper(*str1) != toupper(*str2))
			return false;
		str1++;
		str2++;
	}
	return true;
}
