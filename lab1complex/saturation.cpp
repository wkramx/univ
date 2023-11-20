#include <iostream>
#include <cmath>
#include "saturation.h"

int saturation::limit = 10000;

void saturation::checkFlag() {
	if (abs(getWhole()) >= limit) {
		if (getWhole() < 0) {
			setWhole(-limit);
		}
		else {
			setWhole(limit);
		}
		setFrac(0);
		flagLimit = 1;
	}
}

void saturation::print() {
	if (flagLimit == 1) {
		printf("*");
	}
	floatnum::print();
}

saturation::saturation() :floatnum() {
	flagLimit = 0;
}
saturation::saturation(float value) :floatnum(value) {
	checkFlag();
}
saturation::saturation(floatnum num) :floatnum(num) {
	checkFlag();
}
saturation::saturation(floatnum x, int flag) :floatnum(x) {
	checkFlag();
	if (flag == 1) {
		flagLimit = flag;
	}
}

bool saturation::operator == (saturation a) {
	if ((floatnum)a == (floatnum)*this) {
		return true;
	}
	else {
		return false;
	}
}

saturation saturation::operator + (saturation a) {
	if (flagLimit == 1 || a.flagLimit == 1) {
		return saturation((floatnum)*this + (floatnum)a, 1);
	}
	else {
		return saturation((floatnum)*this + (floatnum)a, 0);
	}
}

saturation saturation::operator - (saturation a) {
	if (flagLimit == 1 || a.flagLimit == 1) {
		return saturation((floatnum)*this - (floatnum)a, 1);
	}
	else {
		return saturation((floatnum)*this - (floatnum)a, 0);
	}
}

saturation saturation::operator * (saturation a) {
	if (flagLimit == 1 || a.flagLimit == 1) {
		return saturation((floatnum)*this * (floatnum)a, 1);
	}
	else {
		return saturation((floatnum)*this * (floatnum)a, 0);
	}
}

saturation saturation::operator / (saturation a) {
	if (flagLimit == 1 || a.flagLimit == 1) {
		return saturation((floatnum)*this / (floatnum)a, 1);
	}
	else {
		return saturation((floatnum)*this / (floatnum)a, 0);
	}
}
