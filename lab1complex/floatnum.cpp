#include <iostream>
#include "floatnum.h"

floatnum::floatnum() {
	whole = 0;
	frac = 0;
	flagMinus = 0;
}

void floatnum::setWhole(int lim) {
	whole = lim;
}

void floatnum::setFrac(int lim) {
	frac = lim;
}

int floatnum::getWhole() {
	return whole;
}

int floatnum::getFrac() {
	return frac;
}

floatnum::floatnum(double f) {
	whole = (int)f;

	if (f == 0) {
		frac = 0;
	}
	else {
		if (f > 0) {
			f -= whole;
		}
		else {
			f += abs(whole);
			flagMinus = 1;
		}
		frac = abs(f * prec);
	}
}

floatnum::floatnum(int wh, int fr) {
	whole = wh;
	frac = fr;
}

int floatnum::prec = 1000;

void floatnum::print() {
	if (flagMinus == 1) {
		printf("-");
	}
	printf("%d.%03d\n", abs(whole), frac);
}

bool floatnum::operator == (floatnum a) {
	if (whole == a.whole && frac == a.frac && flagMinus == a.flagMinus) {
		return true;
	}
	else {
		return false;
	}
}

floatnum operator +(floatnum num1, floatnum num2) {
	
	int sumWhole = num1.whole + num2.whole;
	int sumFrac = num1.frac + num2.frac;

	if (num1.flagMinus == 1 && num2.flagMinus == 1) {
		sumFrac = -sumFrac;
	}
	else if (num1.flagMinus == 1) {
		sumFrac = num2.frac - num1.frac;
	}
	else if (num2.flagMinus == 1) {
		sumFrac = num1.frac - num2.frac;
	}

	if (sumFrac >= floatnum::prec) {
		sumWhole++;
		sumFrac -= floatnum::prec;
	}
	else if (sumFrac < -floatnum::prec) {
		sumWhole--;
		sumFrac += floatnum::prec;
	}

	return sumWhole + (double)sumFrac / floatnum::prec;
}

floatnum operator -(floatnum num1, floatnum num2) {
	int difWhole = num1.whole - num2.whole;
	int difFrac = num1.frac - num2.frac;

	if (num1.flagMinus == 1 && num2.flagMinus == 1) {
		difFrac = -difFrac;
	}
	else if (num1.flagMinus == 1) {
		difFrac = -(num1.frac + num2.frac);
	}
	else if (num2.flagMinus == 1) {
		difFrac = num1.frac + num2.frac;
	}

	if (difFrac >= floatnum::prec) {
		difWhole++;
		difFrac -= floatnum::prec;
	}
	else if (difFrac < -floatnum::prec) {
		difWhole--;
		difFrac += floatnum::prec;
	}

	return difWhole + (double)difFrac / floatnum::prec;
}

floatnum operator *(floatnum num1, floatnum num2) {
	double multNum1;
	double multNum2;

	if (num1.whole >= 0) {
		multNum1 = num1.whole + (double)num1.frac / floatnum::prec;
	}
	if (num1.whole < 0) {
		multNum1 = num1.whole - (double)num1.frac / floatnum::prec;
	}
	else if (num1.flagMinus == 1) {
		multNum1 = -(double)num1.frac / floatnum::prec;
	}
	
	if (num2.whole >= 0) {
		multNum2 = num2.whole + (double)num2.frac / floatnum::prec;
	}
	if (num2.whole < 0) {
		multNum2 = num2.whole - (double)num2.frac / floatnum::prec;
	}
	else if (num2.flagMinus == 1) {
		multNum2 = -(double)num2.frac / floatnum::prec;
	}

	return multNum1 * multNum2;
}

floatnum operator /(floatnum num1, floatnum num2) {
	double divideNum1;
	double divideNum2;

	if (num1.whole >= 0) {
		divideNum1 = num1.whole + (double)num1.frac / floatnum::prec;
	}
	if (num1.whole < 0) {
		divideNum1 = num1.whole - (double)num1.frac / floatnum::prec;
	}
	else if (num1.flagMinus == 1) {
		divideNum1 = -(double)num1.frac / floatnum::prec;
	}

	if (num2.whole >= 0) {
		divideNum2 = num2.whole + (double)num2.frac / floatnum::prec;
	}
	if (num2.whole < 0) {
		divideNum2 = num2.whole - (double)num2.frac / floatnum::prec;
	}
	else if (num2.flagMinus == 1) {
		divideNum2 = -(double)num2.frac / floatnum::prec;
	}

	return divideNum1 / divideNum2;
}
