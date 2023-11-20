#include <iostream>
#pragma once

class floatnum {
private:
	int whole, frac;
	int flagMinus;
	static int prec;
public:
	floatnum();
	floatnum(double);
	floatnum(int, int);

	int getWhole();
	void setWhole(int);
	int getFrac();
	void setFrac(int);
	void print();

	bool operator == (floatnum);
	friend floatnum operator +(floatnum, floatnum);
	friend floatnum operator -(floatnum, floatnum);
	friend floatnum operator *(floatnum, floatnum);
	friend floatnum operator /(floatnum, floatnum);
	
};
