#include <iostream>
#include "saturation.h"
#pragma once

int main() {
	double a, b;

	a = 9942.53;
	b = -211.57;

	saturation num1(a);
	saturation num2(b);

	printf("Num 1: ");
	num1.print();
	printf("\nNum 2: ");
	num2.print();

	printf("\nSum: ");
	saturation sum = num1 + num2;
	sum.print();
	
	printf("Dif: ");
	saturation dif = num1 - num2;
	dif.print();

	printf("Mult: ");
	saturation mult = num1 * num2;
	mult.print();

	printf("Div: ");
	saturation divide = num1 / num2;
	divide.print();
}
