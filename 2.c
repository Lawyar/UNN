#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	int foruser = 0, forpc = 0, user_i = -1, pc_i = -1, attempts = 0, pc_min = 0, pc_max = 1001;;
	char choose = '0', sign = '0';
	printf("Choose the mode: ");
	scanf("%c", &choose);
	switch (choose) {
	case '1':
		foruser = rand() % 1001;
		while (user_i != foruser) {
			printf("Enter the number: ");
			scanf("%d", &user_i);
			if (user_i < foruser)
				printf("Guessed number is bigger");
			if (user_i > foruser)
				printf("Guessed number is less");
		}
		printf("You win! Attempts: %d\n", attempts);
		system("pause");
		return 0;

	case '2':
		printf("Enter the number to pc: ");
		scanf("%d", &forpc);
		while (1) {
			attempts++;
			pc_i = (pc_min + pc_max) / 2;
			printf("He entered: %d. Help him: ", pc_i);
			getchar();
			sign = getchar();
			switch (sign) {
			case '>':
				pc_min = pc_i;
				break;
			case '<':
				pc_max = pc_i;
				break;
			case '=':
				printf("It wins! Attempts: %d", attempts);
				system("pause");
				return 0;
			}
		}
	}
}
