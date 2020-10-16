#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	int* usa, * uspc, num1 = 1, num2, n, c = 1, bull = 0, cow = 0, ci = 0;
	printf("Length: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		c *= 10;
	}
	ci = c / 10;
	num1 = rand() % c + ci;
	uspc = (int*)malloc(n * sizeof(int));
	usa = (int*)malloc(n * sizeof(int));
	int g = n;
	while (num1 != 0) {
		uspc[g - 1] = num1 % 10;
		num1 /= 10;
		g--;
	}
	while (1) {
		printf("Enter the number: ");
		scanf("%d", &num2);
		g = n;
		while (num2 != 0) {
			usa[g - 1] = num2 % 10;
			num2 /= 10;
			g--;
		}
		for(int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++) {
				if (uspc[i] == usa[k]) {
					if (k == i) {
						bull++;
						break;
					}
					else {
						cow++;
					}
				}
			}
		}
		if (bull == n) {
			cow = 0;
		}
		printf("Bull: %d\nCow: %d\n", bull, cow);
		if (bull == n) {
			printf("You win.");
			system("pause");
			return 0;
		}
		bull = cow = 0;
	}
	system("pause");
	return 0;
}

