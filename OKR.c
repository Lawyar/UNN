#include <stdio.h>
#include <math.h>
int main() {
	double radius_1, radius_2, x1, x2, y1, y2, distance;
	printf("First circle radius: ");
	scanf_s("%f", &radius_1);
	printf("Second circle radius: ");
	scanf_s("%f", &radius_2);
	printf("First circle(x): ");
	scanf_s("%f", &x1);
	printf("First circle(y): ");
	scanf_s("%f", &y1);
	printf("Second circle(x): ");
	scanf_s("%f", &x2);
	printf("Second circle(y): ");
	scanf_s("%f", &y2);
	if (x1 > x2) {
		if (y1 > y2) {
			distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
		}
		else {
			distance = sqrt(pow((x1 - x2), 2) + pow((y2 - y1), 2));
		}
	}
	else {
		if (y1 > y2) {
			distance = sqrt(pow((x2 - x1), 2) + pow((y1 - y2), 2));
		}
		else {
			distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		}
	}
	if (distance == radius_1 + radius_2) {
		printf("Окружности касаются друг друга");
	}
	if (distance > radius_1 + radius_2) {
		printf("Окружности не касаются");
	}
	if (distance < radius_1 + radius_2) {
		printf("Одна окружность внутри другой");
	}
	return 0; 
}