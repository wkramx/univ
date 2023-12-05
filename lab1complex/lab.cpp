#include <iostream>
#include "vector.h"

#pragma once

int main() {
	float a, b;

	a = -1324;
	b = 223.5;
	
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

	vector k = 5;
	vector l = 5;
	for (int i = 0; i < k.getLength(); i++) {
		k[i] = i;
	}
	for (int i = 0; i < l.getLength(); i++) {
		l[i] = i + 1;
	}

	std::vector<float> inp1 = { 1234.5, 53.5, 13.3, 0.5, -12 };
	std::vector<float> inp2 = { 9135.15, 9347 , 10001, 2, -135 };
	vector v1(inp1);
	vector v2(inp2);
	vector v3 = v1 + v2;

	printf("\nVector v1:\n");
	v1.print();

	printf("\nVector v2:\n");
	v2.print();

	printf("\nVector v3 = v1 + v2:\n");
	v3.print();

	vector x = k + l;
	printf("\nVector x = k + l:\n");
	x.print();

	vector y = k - l;
	printf("\nVector y = k - l:\n");
	y.print();

	printf("\nAssign y = x:\n");
	y = x;
	y.print();

	printf("\nv1 moved into z:\n");
	vector z = std::move(v1);
	z.print();
	
	printf("\nv1 now:\n");
	v1.print(); // empty, object v1 has been moved
}
