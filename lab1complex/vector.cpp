#include <iostream>
#include "vector.h"

void static error(const char* code) {
	printf("\nError %s", code);
	exit(EXIT_FAILURE);
}

vector::vector(int s) { //s = 0 in the .h already
	if (s <= 0) {
		error("0");
	}
	vect = new saturation[s];
	
	if (vect == 0) {
		error("1");
	}
	length = s;
}

vector::~vector() {
	delete[] vect;
}

void vector::print() {
	for (int i = 0; i < size(); i++) {
		element(i).print();
	}
}

vector::vector(vector& a) :vector(a.length) {
	for (int i = 0; i < size(); i++) {
		element(i) = a.element(i);
	}
}

vector::vector(vector&& a) {
	vect = a.vect;
	length = a.length;
	a.vect = NULL;
	a.length = 0;
}

vector vector::operator + (vector& a) {
	if (length != a.length) {
		error("SUM: Different size");
	}
	vector sum(length);
	for (int i = 0; i < length; i++) {
		sum.element(i) = element(i) + a.element(i);
	}
	return sum;
}

vector vector::operator - (vector& a) {
	if (length != a.length) {
		error("DIF: Different size");
	}
	vector dif(length);
	for (int i = 0; i < length; i++) {
		dif.element(i) = element(i) - a.element(i);
	}
	return dif;
}

saturation& vector::operator[] (int i) {
	if (i < 0 || i > length - 1) {
		error("2");
	}
	return *(vect + i);
}

bool vector::operator == (vector& a) {
	if (length != a.length) {
		return false;
	}
	for (int i = 0; i < length; i++) {
		if (element(i) == a.element(i)) {
			return false;
		}
	}
	return true;
}
