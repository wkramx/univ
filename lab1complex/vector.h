#include "saturation.h";
#include <vector>
#pragma once

class vector {
private:
	int length;
	saturation* vect;
public:
	vector();
	vector(int);
	~vector(); //destructor
	vector(vector&); //copy
	vector(vector&&) noexcept; //move
	vector(std::vector<float>);

	inline int size();
	inline saturation& element(int);

	int getLength();

	saturation& operator [] (int);
	vector operator + (vector&);
	vector operator - (vector&);
	bool operator == (vector&); //compare
	void operator = (vector&); //assign
	
	void print();
};
