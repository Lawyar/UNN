#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "Rus");
	double radius_1, radius_2, x1, x2, y1, y2, distance;
	printf("������ ������ ����������: ");
	scanf_s("%f", &radius_1);
	printf("������ ������ ����������: ");
	scanf_s("%f", &radius_2);
	printf("���������� ������ ������ ����������(x): ");
	scanf_s("%f", &x1);
	printf("���������� ������ ������ ����������(y): ");
	scanf_s("%f", &y1);
	printf("���������� ������ ������ ����������(x): ");
	scanf_s("%f", &x2);
	printf("���������� ������ ������ ����������(y): ");
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
		printf("���������� �������� ���� �����");
	}
	if (distance > radius_1 + radius_2) {
		printf("���������� �� ��������");
	}
	if (distance < radius_1 + radius_2) {
		printf("���� ���������� ������ ������");
	}
	return 0; 
}