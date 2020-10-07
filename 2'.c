#include <stdio.h>

int main() {
	char x;
	int wcount = 0, dcount = 0, wbegin = 1;
	while ((x = getchar()) != '\n') {
		if (((x > '0') && (x < '9')) && wbegin == 1) {
			dcount++;
			wbegin = 0;
		}
		if ((((x < 'Z') && (x > 'A')) || ((x < 'z') && (x > 'a'))) && wbegin == 1) {
			wcount++;
			wbegin = 0;
		}
		if (x == ' ') {
			wbegin = 1;
		}

	}
	printf("digit count: %d\nword count: %d\n", dcount, wcount);
	return 0;
}
