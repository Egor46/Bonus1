#pragma once
#include <iostream>
#include "Vector.h"

class Complex
{
	friend std::istream& operator>>(std::istream& in, Complex& c);
	friend std::ostream& operator<<(std::ostream& out, const Complex& c);
private:
	Vector<double> coord;
public:
	Complex();
	Complex(double x, double y);
	Complex(const Complex& other);

	Complex operator+(const Complex& other) const;
	Complex operator*(const Complex& other) const;
	Complex& operator=(const Complex& other);
	double& operator[](int idx) const { return coord[idx]; };
};

