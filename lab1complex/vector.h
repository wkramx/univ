#include "saturation.h";
#pragma once

class vector {
private:
	int length;
	saturation* vect;
public:
	vector(int s = 0); //default
	~vector(); //destructor
	vector(vector&); //copy, const vector& maybe?????
	vector(vector&&); //move constructor - creates a copy of an object and transfers (not copies) the content to another object

	inline int size() {
		return length;
	}
	inline saturation& element(int i) {
		return *(vect + i);
	}

	saturation& operator [] (int);
	bool operator == (vector&); //assignment operator, const vector& maybe?????
	vector operator + (vector&);
	vector operator - (vector&);
	void print();
};
