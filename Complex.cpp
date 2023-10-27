#include "Complex.h"
#include <iomanip>

std::istream& operator>>(std::istream& in, Complex& c)
{
	in >> c[0] >> c[1];
	return in;
}

std::ostream& operator<<(std::ostream& out, const Complex& c)
{
	out << c[0] << std::showpos << c[1] << std::noshowpos << 'i';
	return out;
}

Complex::Complex()
{
	coord = Vector<double>(2);
}

Complex::Complex(double x, double y)
{
	coord = Vector<double>(2);
	coord[0] = x;
	coord[1] = y;
}

Complex::Complex(const Complex& other)
{
	coord = Vector<double>(2);
	coord[0] = other[0];
	coord[1] = other[1];
}

Complex Complex::operator*(const Complex& other) const
{
	return Complex(coord[0] * other[0] - coord[1] * other[1], coord[0] * other[1] + coord[1] * other[0]);
}

Complex& Complex::operator=(const Complex& other)
{
	coord = other.coord;
	return *this;
}

Complex Complex::operator+(const Complex& other) const
{
	return Complex(coord[0] + other[0], coord[1] + other[1]);
}
