#include <stdio.h>

int main(){
	double dsp, dvp, wood;
	double doors_weight, back_weight, covers_weight, shelves_weight, sides_weight, weight;
	int h, w, d, shelves_n;
	float w_forc;
	printf("Dsp density: ");
	scanf_s("%f", &dsp);
	printf("Dvp density: ");
	scanf_s("%f", &dvp);
	printf("Wood density: ");
	scanf_s("%f", &wood);
	printf("h: ");
	scanf_s("%d", &h);
	printf("w: ");
	scanf_s("%d", &w);
	printf("d: ");
	scanf_s("%d", &d);
	back_weight = dvp * h * w * 0.005;
	doors_weight = 2 * h * w * wood;
	covers_weight = 2 * w * d * 0.015;
	sides_weight = 2 * d * dsp * w * 0.015;
	w_forc = w - 0.3;
	shelves_n = h / 40;
	shelves_weight = w * d * shelves_n;
	weight = doors_weight + back_weight + covers_weight + sides_weight + shelves_weight;
	printf("%f", weight);
	system("pause");
	return 0;
}
