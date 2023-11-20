#include <iostream>
#include "floatnum.h"
#pragma once

class saturation : public floatnum {
private:
	static int limit;
	int flagLimit;
public:
	saturation();
	saturation(float);
	saturation(floatnum);
	saturation(floatnum, int);
	void print();
	void checkFlag();

	bool operator == (saturation);
	saturation operator + (saturation);
	saturation operator - (saturation);
	saturation operator * (saturation);
	saturation operator / (saturation);
};
