#include <iostream>
#include <cmath>
#include<math.h>


// Math

// Converting degrees to radians for the math library functions
double Convert(double degrees, double radians, int d /* Mode */) {
	// Switch for d variable
	switch (d) {
		case 1:
			radians = (degrees * (3.14159265359/180));
			return radians;
			break;
		case 2:
			degrees = radians/(3.14159265359/180);
			return degrees;
	}
	return 0;
}

// Pythagorean theorem
double pythag(float a,float b,float c,int d) {
	if (d==0) {
		a=std::sqrt(std::pow(c,2)-std::pow(b,2));
		return a;
	}
	else if (d==1) {
		b=std::sqrt(std::pow(c,2)-std::pow(a,2));
		return b;
	}
	else if (d==2) {
		c=std::sqrt(std::pow(a,2)+std::pow(b,2));
		return c;
	}
	return 0;
}

	// Pythagorean theorem but 3d
float pythag_3d(float x, float y, float z, float c, int d) {
	if (d==0) {
		x=std::sqrt(std::pow(c,2)-std::pow(z,2)-std::pow(y,2));
		return x;
	}
	else if (d==1) {
		y=std::sqrt(std::pow(c,2)-std::pow(y,2)-std::pow(z,2));
		return y;
	}
	else if (d==2) {
		z=std::sqrt(std::pow(c,2)-std::pow(y,2)-std::pow(x,2));
		return z;
	}
	else if (d==3) {
		c=std::sqrt(std::pow(x,2)+std::pow(y,2)+std::pow(z,2));
		return c;
	}
	return 0;
}

// Math