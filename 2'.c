#include <stdio.h>
#include <ctype.h>

int main() {
	char x;
	int wcount = 0, dcount = 0, wbegin = 1;
	while ((x = getchar()) != '\n') {
		if (isdigit(x) && wbegin == 1) {
			dcount++;
			wbegin = 0;
		}
		if (isalpha(x) && wbegin == 1) {
			wcount++;
			wbegin = 0;
		}
		if (iscntrl(x) || isspace(x)) {
			wbegin = 1;
		}

	}
	printf("digit count: %d\nword count: %d\n", dcount, wcount);
	return 0;
}