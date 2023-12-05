#include <iostream>
#include "vector.h"

void static error(const char* code) {
	printf("\nError %s", code);
	exit(EXIT_FAILURE);
}

inline int vector::size() {
	return length;
}

inline saturation& vector::element(int i) {
	return vect[i];
}

int vector::getLength() {
	return length;
}

vector::vector() {
	vect = new saturation[0];
	length = 0;
}

vector::vector(int s = 0) {
	if (s < 0) {
		error("0");
	}
	vect = new saturation[s];
	
	if (vect == 0) {
		error("1");
	}
	length = s;
}

vector::~vector() {
	if (length != NULL && vect != nullptr) {
		delete[] vect;
	}
}

vector::vector(std::vector<float> a) :vector(a.size()) {
	for (int i = 0; i < length; i++) {
		element(i) = a[i];
	}
}

void vector::print() {
	for (int i = 0; i < size(); i++) {
		element(i).print();
	}
}

vector::vector(vector& a) :vector(a.length) {
	for (int i = 0; i < size(); i++) {
		element(i) = a[i];
	}
}

vector::vector(vector&& a) noexcept {
	vect = a.vect;
	length = a.length;
	a.vect = nullptr;
	a.length = 0;
}

saturation& vector::operator [] (int i) {
	if (i < 0 || i + 1 > length) {
		error("2");
	}
	return vect[i];
}

vector vector::operator + (vector& a) {
	if (length != a.length) {
		error("SUM: Different size");
	}
	vector sum(length);
	for (int i = 0; i < length; i++) {
		sum[i] = element(i) + a[i];
	}
	return sum;
}

vector vector::operator - (vector& a) {
	if (length != a.length) {
		error("DIF: Different size");
	}
	vector dif(length);
	for (int i = 0; i < length; i++) {
		dif[i] = element(i) - a[i];
	}
	return dif;
}

void vector::operator = (vector& a) {
	if (vect != a.vect) {
		for (int i = 0; i < size(); i++) {
			element(i) = a[i];
		}
	}
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
