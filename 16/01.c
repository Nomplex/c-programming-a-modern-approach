#include <stdio.h>

const struct country_code {
    char *country;
    int code;
} country_codes[] =
	{{"Argentina", 54}, {"Bangladesh", 889}, {"Brazil", 55},
	{"Burma (Myanmar)", 95}, {"China", 86}, {"Colombia", 57},
	{"Congo, Dem. Rep. of", 243}, {"Egypt", 20}, {"Ethiopia", 251}, 
	{"France", 33}, {"Germany", 49}, {"India", 91},
	{"Indonesia", 62}, {"Iran", 98}, {"Italy", 39},
	{"Japan", 81}, {"Mexico", 52}, {"Nigeria", 234},
	{"Pakistan", 92}, {"Philippines", 63}, {"Poland", 48},
	{"Russia", 7}, {"South Africa", 27}, {"South Korea", 82},
	{"Spain", 34}, {"Sudan", 249}, {"Thailand", 66},
	{"Turkey", 90}, {"Ukraine", 380}, {"United Kingdom", 44},
	{"United States", 1}, {"Vietnam", 84}};

int search_country_codes(int code);

int main(void) {
	int code, index;
	printf("Enter an international dialing code: ");
	scanf("%d", &code);

	index = search_country_codes(code);

	if (index == -1)
		printf("ERROR: Dialing code %d not found\n", code);
	else
		printf("Dialing code %d belongs to: %s\n", code, country_codes[index].country);

	return 0;
}

/* Didn't really need to put this in its own function */
int search_country_codes(int code) {
	/* Could've probably put this into a define macro */
	for (size_t i = 0; i < sizeof(country_codes) / sizeof(struct country_code); i++) {
		if (country_codes[i].code == code)
			return (int) i;
	}

	return -1;
}
